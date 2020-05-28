/*
 * @Author: liuyanan 
 * @Date: 2020-05-10 11:00:58 
 * @Last Modified by: liuyanan
 * @Last Modified time: 2020-05-10 11:10:15
 */


#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

/*

    https://blog.csdn.net/ivan_zgj/article/details/51519941
    http://www.cs.utexas.edu/users/djimenez/utsa/cs3343/lecture17.html
    https://www.programiz.com/dsa/insertion-into-a-b-tree

    docs/BTree_1.html docs/BTree_2.html

    B树有以下性质：
        性质1. 根结点至少有两个子女；
        性质2. 每个非根节点所包含的关键字个数 j 满足：t-1 <= j <= 2t-1；
        性质3. 除根结点以外的所有结点（不包括叶子结点）的度数正好是关键字总数加1；
        性质4. 所有的叶子结点都位于同一层。

    B树 和 B+树 的区别
        https://baijiahao.baidu.com/s?id=1655665549235267594

        3、B-树和B+树的区别
        （1）B+树查询时间复杂度固定是logn，B-树查询复杂度最好是 O(1)。
        （2）B+树相邻接点的指针可以大大增加区间访问性，可使用在范围查询等，而B-树每个节点 key 和 data 在一起，则无法区间查找。
        （3）B+树更适合外部存储，也就是磁盘存储。由于内节点无 data 域，每个节点能索引的范围更大更精确
        （4）注意这个区别相当重要，是基于（1）（2）（3）的，B-树每个节点即保存数据又保存索引，所以磁盘IO的次数很少，
            B+树只有叶子节点保存，磁盘IO多，但是区间访问比较好。

        MongoDB 是文档型的数据库，是一种 nosql，它使用类 Json 格式保存数据。
            MongoDB使用B-树，所有节点都有Data域，只要找到指定索引就可以进行访问，无疑单次查询平均快于Mysql。
        Mysql作为一个关系型数据库，数据的关联性是非常强的，区间访问是常见的一种情况。
            B+树由于数据全部存储在叶子节点，并且通过指针串在一起，这样就很容易的进行区间遍历甚至全部遍历。
*/

class BTreeNode {
public:
    BTreeNode(bool is_leaf=false): _is_leaf(is_leaf) {}

    // 孩子节点域操作
    void insert_child_at(int pos, BTreeNode* p_node) {
        // 在pos之前插入新节点 在指定位置插入孩子，因为是有顺序的
        auto iter = _children.begin();
        if(pos > 0) {
            advance(iter, pos);
        }
        _children.insert(iter, p_node);
    }

    BTreeNode* get_child_at(int pos) {
        return _children[pos];
    }

    size_t children_size() {
        return _children.size();
    }

    // 数据域操作
    void insert_key(int k) {
        /*_keys 是有序的所以要查找*/
        auto iter = _keys.begin();
        for(; iter!=_keys.end(); ++iter) {
            if(k < *iter) {
                break;
            }
        }
        _keys.insert(iter, k);
    }

    void insert_key_at(size_t pos, int k) {
        /*_keys 是有序的所以要查找*/

        size_t i = 0;
        auto iter = _keys.begin();
        while(i++ < pos) {
            ++iter;
        }
        _keys.insert(iter, k);
    }

    size_t key_size() {
        return _keys.size();
    }

    bool full(int t) {
        return _keys.size() == (2 * t) - 1;
    }

    // 叶子节点标记
    bool leaf() {
        return _is_leaf;
    }

    string display_key() {
        ostringstream oss;
        for(auto item : _keys) {
            oss << item << " ";
        }
        return oss.str();
    }

private:
    vector<int> _keys;                 // 存储数据:    y是从小到大排序的
    vector<BTreeNode*> _children;      // 存储孩子节点：指向孩子指针   
    
    bool _is_leaf;                     // 是否是叶子节点

    friend class BTree;
};

struct STSearchResult {
    STSearchResult(): p_node(nullptr), idx(0){
    }

    STSearchResult(BTreeNode *node, size_t i): p_node(node), idx(i){
    }

    BTreeNode *p_node;
    size_t idx;
};

class BTree {
public:
    BTree(int t) {
        // 第一个节点，所以也是叶子节点
        _root = new BTreeNode(true);
        _t = t;
    }

    /*************************  插入  *************************/
    void insert(int k) {
        cout << "start insert: " << k << endl;
        auto old_root = _root;
        if(old_root->full(_t)) {
            /*
                插入的时候优先在根节点，因为根节点常驻内存，直到根节点满了
                根节点满了，需要先分裂 (因为每次插入优先检查根节点)
                    1. 新生成一个新的根节点
                    2. 然后把老的根节点作为孩子重新链接起来
                    3. 然后分裂老的根节点
                对应 docs/BTree_2.html 中插入7的情况
                不好明白的处在split这里， split不仅要拆分，还要把median放到父节点合适的位置上
             */
            _root = new BTreeNode();
            _root->insert_child_at(0, old_root);    // 为什么是0，因为父节点拆分后一定有两个孩子节点
            _split_child(_root, 0);
            _do_insert_non_full_recursively(_root, k);
            cout << "after insert(root full) " << k << ": " << endl;
        } else {
            // 这里是递归调用，选取合适的孩子节点
            _do_insert_non_full_recursively(old_root, k);
            cout << "after insert(root not full) " << k << ": " << endl;
        }
    }

    void display(BTreeNode* p_node, int& level) {
        ostringstream oss;
        oss << "\tlevel: " << level << ", keys count: " << p_node->key_size() << "\t data: ";

        for(auto item : p_node->_keys) {
            oss << item << " ";
        }
        cout << oss.str() << endl;

        level += 1;

        if(p_node->children_size() > 0) {
            for(auto p_child: p_node->_children) {
                display(p_child, level);
            }
        }
    }

    STSearchResult search(BTreeNode* p_node, int k) {
        int idx = 0;
        
        /*
                    key0       key1      key2
                 V         V          V          V
                ch0       ch1        ch2        ch3
        */

        // 找到在哪个区间里边
        while(idx < p_node->key_size() && k > (p_node->_keys[idx])) {
            ++idx;
        }

        if(idx < p_node->key_size() && k == (p_node->_keys[idx])) {
            return STSearchResult(p_node, idx);
        }

        if(p_node->leaf()) {
            return STSearchResult();
        }

        return search(p_node->get_child_at(idx), k);
    }

private:
    void _do_insert_non_full_recursively(BTreeNode* p_node, int k) {
        // 进入到这个函数的 p_node都是没有full的
        
        if(p_node->leaf()) {
            /*
                是叶子节点，并且没有full，直接插入（插入后依然是排序的）
                所有的新元素都在叶子节点上
             */
            p_node->insert_key(k);
        } else {
            /* 
                不是是叶子节点，需要查找在哪个child上插入
                注意这里，keys是有序的，而且children 也是有序的
                    children一定比keys大1 （性质3）
                    key的度最多是2t-1，所以其children最多有2t个
             */
            int i = 0;
            for(; i<p_node->_keys.size(); ++i) {
                if(k < p_node->_keys[i]) {
                    break;
                }
            }
            cout << "find child: " << i;
            /* 注意这里，我们不是检查cur node 是不是full了，而是检查它的child是不是full了
                split的过程是从上而下进行的，每次插入时都会检查root是不是full了
                Step 10: Insert 4
                    It would be nice to just stick 4 in with 3, but the B-Tree algorithm
                    requires us to split the full root.  Note that, if we don't do this and
                    one of the leaves becomes full, there would be nowhere to put the middle
                    key of that split since the root would be full, thus, this split of the
                    root is necessary:
             */
            if(p_node->get_child_at(i)->full(_t)) {
                cout << ", child is full will split" << endl;
                _split_child(p_node, i);
                if(k > p_node->_keys[i]) {
                    ++i;
                }
            }

            _do_insert_non_full_recursively(p_node->_children[i], k);
        }
    }

    void _split_child(BTreeNode* p_parent_node, int pos_child_to_split) {
        /* 
            注意 我们要分裂的是孩子节点
            在分裂后需要更新 parent_node 的数据
         */
        auto p_node_to_split = p_parent_node->get_child_at(pos_child_to_split);
        auto p_new_node = new BTreeNode(p_node_to_split->leaf());  //  节点类型和要分裂的节点保持一致

        /*
            2. 拷贝数据，分两部分
                2.1 拷贝数据
                2.2 拷贝孩子节点
        */
        /* 
            2.1 拷贝数据
                之所以要 split 节点是因为该节点的 keys 个数为 2t-1 个了
                    所有分裂后的两个孩子节点分别有 t-1 个 ，中间的那个元素放到父节点上
                把要split的node的右半部分 拷贝 到新节点里边
                
                
                1..........t..........2t-1  // 从1开始的
                0.........t-1.........2t-2  // 从0开始的
                      t    ^    t-1
                           ^
                    这个元素要放到父节点里边去
         */
        cout << "split_node(len=" << p_node_to_split->_keys.size() << ")" << ", copying data to right node:";
        int i = 2 * _t - 2;
        while(i > _t-1) {
            auto key = p_node_to_split->_keys[i];
            cout << "[" << i << "]=" << key << " ";
            //p_new_node->_keys.push_back(key);
            // 因为这里是把 p_node_to_split 从右往左额顺序拷贝的，所以每次都要在new_node的首位插入
            p_new_node->_keys.insert(p_new_node->_keys.begin(), key);
            p_node_to_split->_keys.pop_back();
            i-=1;
        }
        cout << endl;
        
        /* 
            2.2. 拷贝孩子节点
                注意 如果key的个数是2t-1, 那孩子节点个数为 2t 个
         */
        if(!p_node_to_split->leaf()) {
            int i = 2 * _t - 1;
            while(i > _t-1) {
                auto child = p_node_to_split->_children[i];
                cout << "split_node: copying child:" << child << endl;
                // 因为这里是把 p_node_to_split 从右往左额顺序拷贝的，所以每次都要在new_node的首位插入
                p_new_node->_children.insert(p_new_node->_children.begin(), child);
                p_node_to_split->_children.pop_back();
                i-=1;
            }
        }
        // having "chopped off" the right half of p_node_to_split, it now has t-1 keys

        // 下边开始查找brother节点在parent中的位置，并设置关系
        p_parent_node->insert_child_at(pos_child_to_split+1, p_new_node);
        p_parent_node->insert_key_at(pos_child_to_split, p_node_to_split->_keys[_t-1]);
    
        p_node_to_split->_keys.pop_back();

        cout << "\tafter split parent: " << p_parent_node->display_key() << endl;
        cout << "\tafter split left child: " << p_node_to_split->display_key() << endl;
        cout << "\tafter split right child: " << p_new_node->display_key() << endl;

        int level = 0;
        cout << "\tafter split: \n";
        display(_root, level);
    }

public:
    int _t;                 // B树的度, 一个结点的关键字的个数是 [t-1, 2t-1] 个
    BTreeNode* _root;       // B树的根节点
};


int main(int argc, char const *argv[])
{
    BTree b_tree(2);

    auto data = {5,9,3,7,1,2,8,6,0,4};
    for(auto item : data) {
        b_tree.insert(item);

        int level = 0;
        b_tree.display(b_tree._root, level);

        cout << "\n\n" << endl;
    }

    STSearchResult ret = b_tree.search(b_tree._root, 5);
    cout << "search 5 result nodes=[ " << ret.p_node->display_key() << "], idx=" << ret.idx << endl;

    ret = b_tree.search(b_tree._root, 0);
    cout << "search 0 result nodes=[ " << ret.p_node->display_key() << "], idx=" << ret.idx << endl;

    ret = b_tree.search(b_tree._root, 6);
    cout << "search 6 result nodes=[ " << ret.p_node->display_key() << "], idx=" << ret.idx << endl;

    ret = b_tree.search(b_tree._root, 7);
    cout << "search 7 result nodes=[ " << ret.p_node->display_key() << "], idx=" << ret.idx << endl;
    
    return 0;
}
