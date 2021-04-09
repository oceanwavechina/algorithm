/*
 * @Author: liuyanan 
 * @Date: 2019-06-23 16:11:53 
 * @Last Modified by: liuyanan
 * @Last Modified time: 2019-06-23 17:25:40
 */

/*
    实现一致性hash
    copied from https://blog.csdn.net/xinzhongtianxia/article/details/81323490

    # CS168: The Modern Algorithmic Toolbox Lecture #1: Introduction and Consistent Hashing
    虚拟节点还可以对处理能力强的节点进行倾斜，也就是可以对处理能力强的节点生成多个虚拟节点

	这里介绍了jump hashing， 适合sharding，但是不适合load-balancing
    https://itnext.io/introducing-consistent-hashing-9a289769052e

	Rendezvous 算是和一致性hash很像的方法
		基本思想都是先把 node 做hash，保存一下，生成一个 hash-set，然后根据一定的规则去在这些hash-set 中去查找
		区别在于：
			Rendezvous是每次找 node+key 之后的hash 可以得到最大值的那个 node
			一致性hash是 找到 key 和 node 的 hash 值 最为接近的那个 node

	google 的jump hashing是 mod 类型的hash一样，不需要保存hash值。
*/

#include <iostream>
#include <sstream>
#include <map>
#include <unordered_map>
#include <functional>

using namespace std;

typedef ::std::string TNode;
typedef size_t THash;

class ConsistentHash {
public:
    ConsistentHash(size_t n_virtual_replicas)
        : _n_virtual_replicas(n_virtual_replicas) { }

    void add(const TNode& node) {
        ostringstream oss;
        oss << "add:" << node;
        for (size_t i = 0; i < _n_virtual_replicas; ++i) {
            size_t hash = _cal_virtual_node_hash(node, i);
            _node_hash_circle[hash] = node;
            _node_names[hash] = node + "_v" + to_string(i);
            oss << " -> virtual" << i << ":" << hash;
        }
        cout << oss.str() << endl;
    }

    void remove(TNode node) {
        for(size_t i=0; i< _n_virtual_replicas; ++i) {
            _node_hash_circle.erase(_cal_virtual_node_hash(node, i));
        }
    }

    TNode get( const string& key) {
        if(_node_hash_circle.empty()) {
            return TNode();
        }

        // key 的 hash
        long key_hash = _cal_key_hash(key);

        //
        // 如果 _circle 里边有这个hash对应的node，直接返回
        // 没有的话，就要找大于这个hash值, 并且顺时针，紧挨着的node
        //
        auto it = _node_hash_circle.find(key_hash);
        if(it != _node_hash_circle.end()) {
            display_circle("node for " + key + " is: ", it->first);
            return it->second;
        }

        //
        // 顺时针查找最近的一个node
        //
        auto it_upper = _node_hash_circle.upper_bound(key_hash);
        if(it_upper != _node_hash_circle.end()) {
            display_circle("node for " + key + " is: ", it_upper->first);
            return it_upper->second;
        } else {
            display_circle("node for " + key + " is: ", _node_hash_circle.begin()->first);
            return _node_hash_circle.begin()->second;
        }
    }

    size_t size() {
        //display_circle(0);
        return _node_hash_circle.size();
    }

    void display_circle(string msg, const THash& target_hash) {
        ostringstream oss;
        oss << msg;
        for(auto item : _node_hash_circle) {
            if(target_hash == item.first)
                //oss << "\t\033[4m*" << _node_names[item.first] << "*";
                oss << "\t*" << _node_names[item.first] << "*";
            else
                oss << "\t" << _node_names[item.first];
        }
        cout << oss.str() << endl;
    }

private:
    THash _cal_virtual_node_hash(const TNode& node, size_t seq) {
        return _hash_func(node + to_string(seq));
    }

    THash _cal_key_hash(const string& key) {
        return _hash_func(key);
    }

private:
    std::hash<std::string> _hash_func;
    size_t _n_virtual_replicas;

    /*
     fix(IMPORTANT):
     	 这里一定要是multimap，因为不同的node或是key，可能会hash到同一个值
     	 用map的话可能会覆盖原来的元素，发生严重的问题
     	 这里存的是node的hash，node是有限的，而且hash的空间是非负整数范围，node最多可能只有几万个
     	 所以这里用map问题也不大
     */
    // multimap<THash/*hash*/, TNode> _node_hash_circle;
    map<THash/*hash*/, TNode> _node_hash_circle;

    unordered_map<THash/*hash*/, string/*node_name*/> _node_names;
};

int main()
{
    /*
    std::hash<std::string> _hash_func;
    size_t hash = _hash_func("string"); 
    cout << hash << endl;
    */

    ConsistentHash c_hash(4);
    c_hash.add(TNode("node1"));
    c_hash.add(TNode("node2"));
    c_hash.add(TNode("node3"));

    c_hash.size();

    TNode node = c_hash.get("dummy_key");

    c_hash.remove("node1");

    node = c_hash.get("dummy_key");

    node = c_hash.get("redis_key");

    return 0;
}
