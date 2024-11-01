#ifndef TREE_H
#define TREE_H

namespace pop
{
    template<typename T>
    struct treeNode
    {
        treeNode* left;
        T data;
        treeNode* right;

        public:
             treeNode(T val): data(val),left(nullptr),right(nullptr){ }
    };
    
    class BinaryTree
    {
    private:
        
    public:
        BinaryTree() = default;
        ~BinaryTree() = default;
        // void createBinaryTree();
    };
    
    // BinaryTree::BinaryTree()
    // {
    // }
    
    // BinaryTree::~BinaryTree()
    // {
    // }
    
       
} // namespace pop


#endif