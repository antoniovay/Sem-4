//
//  BinaryTreeTester.hpp
//  Lab 2 "BinaryTree"
//
//  Created by Antony Miroshnichenko on 04.04.2024.
//



#include <vector>
#include "BinaryTree.hpp"



class BinaryTreeTester
{
    
    friend class SearchTreeTester;
    
public:
    
    BinaryTreeTester(const bool useConsoleOutput, const bool enableAllTests = true);
    virtual ~BinaryTreeTester() = default;
    
    void test(const int size);

    bool addAndCountCheckEnabled() const;
    bool destructorCheckEnabled() const;
    bool removeCheckEnabled() const;
    bool clearCheckEnabled() const;
    bool assignCheckEnabled() const;
    bool heightCheckEnabled() const;

    void setAddAndCountCheckEnabled(const bool enabled);
    void setDestructorCheckEnabled(const bool enabled);
    void setRemoveCheckEnabled(const bool enabled);
    void setClearCheckEnabled(const bool enabled);
    void setAssignCheckEnabled(const bool enabled);
    void setHeightCheckEnabled(const bool enabled);

protected:
    using TreeNodes = std::vector<BinaryTree::Node *>;

protected:
    int invalidKey() const;

    virtual BinaryTree *allocateTree();
    virtual void check_addAndCount(const BinaryTree *tree, const int size);
    virtual void check_remove(BinaryTree *tree, const int key,
                              const bool result, const int size);
    virtual void check_clear(const BinaryTree *tree, const int size);
    virtual void check_assign(const BinaryTree *first,
                              const BinaryTree *second);
    virtual void check_height(const BinaryTree &tree, const int size);
    
    
protected:
    virtual void assign();
    std::vector<int> generateKeys();
    int m_maxSize;
    
    

private:
    void deallocateTree(BinaryTree *tree);
    void addAndCount();
    void destructor();
    void remove();
    void clear();
    void height();
    void height_trivialCases();
    void height_longOnlyLeftSubtree();
    void height_longOnlyRightSubtree();
    void height_longOnlyLeftAndRightSubtrees();
    void height_longRandomZigzagSubtrees();
    TreeNodes treeNodes(const BinaryTree *tree);
    
private:
    bool m_useConsoleOutput;
    bool m_addAndCountCheckEnabled;
    bool m_destructorCheckEnabled;
    bool m_removeCheckEnabled;
    bool m_clearCheckEnabled;
    bool m_assignCheckEnabled;
    bool m_heightCheckEnabled;
};
