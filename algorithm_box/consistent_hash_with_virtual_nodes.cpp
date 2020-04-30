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
            _circle[hash] = node;
            _node_names[hash] = node + "_v" + to_string(i);
            oss << " -> virtual" << i << ":" << hash;
        }
        cout << oss.str() << endl;
    }

    void remove(TNode node) {
        for(size_t i=0; i< _n_virtual_replicas; ++i) {
            _circle.erase(_cal_virtual_node_hash(node, i));
        }
    }

    TNode get( const string& key) {
        if(_circle.empty()) {
            return TNode();
        }

        // key 的 hash
        long key_hash = _cal_key_hash(key);

        //
        // 如果 _circle 里边有这个hash对应的node，直接返回
        // 没有的话，就要找大于这个hash值, 并且顺时针，紧挨着的node
        //
        auto it = _circle.find(key_hash);
        if(it != _circle.end()) {
            display_circle("node for " + key + " is: ", it->first);
            return it->second;
        }

        //
        // 顺时针查找最近的一个node
        //
        auto it_upper = _circle.upper_bound(key_hash);
        if(it_upper != _circle.end()) {
            display_circle("node for " + key + " is: ", it_upper->first);
            return it_upper->second;
        } else {
            display_circle("node for " + key + " is: ", _circle.begin()->first);
            return _circle.begin()->second;
        }
    }

    size_t size() {
        //display_circle(0);
        return _circle.size();
    }

    void display_circle(string msg, const THash& target_hash) {
        ostringstream oss;
        oss << msg;
        for(auto item : _circle) {
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
    map<THash/*hash*/, TNode> _circle;

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