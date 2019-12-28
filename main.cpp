#include <iostream>
#include "binaryTree.h"
#include "144.h"
#include "94.h"
#include "145.h"
#include "102.h"
#include "100.h"
#include "101.h"
#include "226.h"
#include "257.h"
#include "112.h"
#include "113.h"
#include "129.h"
#include "111.h"
#include "104.h"
#include "110.h"
#include "250.h"
#include "366.h"
#include "337.h"

#include <vector>


// all tree knowledges: https://cspiration.com/leetcodeClassification#1
using namespace std;

template<class T>
void printVector(vector<T> &a){
    for (int i =0; i < a.size(); ++i){
        cout << a[i] << ",";
    }
    cout << endl;
}

template<class T>
void print2DVector(vector<vector<T>> &a){
    for (int i =0; i < a.size(); ++i){
        vector<int> &aa = a[i];
        for (int j = 0; j < aa.size(); ++j){
            cout << aa[j] << ",";
        }
        cout << endl;
    }
    cout << endl;
}
int main() {
    TreeNode* root1 = new TreeNode(1);
    TreeNode* n1 = new TreeNode(2);
    TreeNode* n2 = new TreeNode(3);
    root1->right = n1;
    n1->left = n2;

    TreeNode* root2 = new TreeNode(3);
    TreeNode* n21 = new TreeNode(9);
    TreeNode* n22 = new TreeNode(20);
    TreeNode* n23 = new TreeNode(15);
    TreeNode* n24 = new TreeNode(7);
    root2->left = n21;
    root2->right = n22;
    n21->left = n23;
    n21->right = n24;

    TreeNode* root3 = new TreeNode(3);
    TreeNode* n31 = new TreeNode(9);
    TreeNode* n32 = new TreeNode(9);
    TreeNode* n33 = new TreeNode(15);
    TreeNode* n34 = new TreeNode(15);
    root3->left = n31;
    root3->right = n32;
    n31->left = n33;
    n32->right = n34;

    TreeNode* root4 = new TreeNode(5);
    TreeNode* n41 = new TreeNode(4);
    TreeNode* n42 = new TreeNode(5);
    TreeNode* n43 = new TreeNode(4);
    TreeNode* n44 = new TreeNode(4);
    TreeNode* n45 = new TreeNode(5);
    TreeNode* n46 = new TreeNode(5);
    root4->left = n41;
    root4->right = n42;
    n41->left = n43;
    n41->right = n44;
    n42->right = n45;
    n45->right = n46;

    TreeNode* root5 = new TreeNode(5);
    TreeNode* n51 = new TreeNode(5);
    TreeNode* n52 = new TreeNode(5);
    TreeNode* n53 = new TreeNode(5);
    TreeNode* n54 = new TreeNode(5);
    TreeNode* n55 = new TreeNode(5);
    TreeNode* n56 = new TreeNode(5);
    root5->left = n51;
    root5->right = n52;
    n51->left = n53;
    n51->right = n54;
    n52->right = n55;
    n55->right = n56;
    // preoder
    cout << "pre order" << endl;
    Solution144 s144;
    vector<int> r144p1 = s144.p144_preorderTraversal(root1);
    vector<int> r144p2 = s144.p144_preorderTraversalIter(root1);
    printVector(r144p1);
    printVector(r144p2);

    //inorder
    cout << "inorder" << endl;
    Solution94 s94;
    vector<int> r94p1 = s94.p94_inorderTraversal(root1);
    vector<int> r94p2 = s94.p94_inorderTraversalIter(root1);
    printVector(r94p1);
    printVector(r94p2);

    cout << "post order" << endl;

    Solution145 s145;
    vector<int> r145p1 = s145.p145_postorderTraversal(root1);
    vector<int> r145p2 = s145.p145_postorderTraversalIter(root1);
    printVector(r145p1);
    printVector(r145p2);

    cout << "level order" << endl;
    Solution102 s102;
    vector<vector<int>> r102p1 = s102.p102_levelOrder(root2);
    print2DVector(r102p1);

    cout << "same tree" << endl;
    Solution100 s100;
    cout << s100.p100_isSameTree(root1,root1) << endl;
    cout << s100.p100_isSameTree(root1,root2) << endl;
    cout << s100.p100_isSameTreeIter(root1,root1) << endl;
    cout << s100.p100_isSameTreeIter(root1,root2) << endl;

    cout << "is symmetric " << endl;
    Solution101 s101;
    cout << s101.p101_isSymmetric(root1) << endl;
    cout << s101.p101_isSymmetric(root3) << endl;

    cout << "invert Tree" << endl;
    Solution226 s226;
    vector<int> r226r1 = s144.p144_preorderTraversal(s226.p226_invertTree(root2));
    printVector(r226r1);
    vector<int> r226r2 = s144.p144_preorderTraversal(s226.p226_invertTreeIter(root2));
    printVector(r226r2);

    cout << "Binary Tree Paths" << endl;
    Solution257 s257;
    vector<string> r257r1 = s257.p257_binaryTreePathsIter(root2);
    printVector(r257r1);
    vector<string> r257r2 = s257.p257_binaryTreePaths(root2);
    printVector(r257r2);

    cout << "Path Sum" << endl;
    Solution112 s112;
    cout << s112.p112_hasPathSumIter(root2, 23)<< endl;
    cout << s112.p112_hasPathSum(root2, 23)<< endl;

    cout << "Path Sum II" << endl;
    Solution113 s113;
    vector<vector<int>> r113r1 = s113.p113_pathSum(root2, 23);
    print2DVector(r113r1);

    cout << "Sum Root to Leaf Numbers" << endl;
    Solution129 s129;
    cout << s129.p129_sumNumbers(root1) << endl;

    cout << "Minimum Depth of Binary Tree" << endl;
    Solution111 s111;
    cout << s111.p111_minDepth(root1) << endl;
    cout << s111.p111_minDepth(root2) << endl;
    cout << s111.p111_minDepth(root3) << endl;

    cout << "Max Depth of Binary Tree" << endl;
    Solution104 s104;
    cout << s104.p104_maxDepth(root1) << endl;
    cout << s104.p104_maxDepth(root2) << endl;
    cout << s104.p104_maxDepth(root3) << endl;

    cout << "Balanced Binary Tree" << endl;
    Solution110 s110;
    cout << s110.p110_isBalanced(root1) <<endl;
    cout << s110.p110_isBalanced(root2) <<endl;
    cout << s110.p110_isBalanced(root3) <<endl;

    cout << "Count Univalue Subtrees" << endl;
    Solution250 s250;
    cout << s250.p250_countUnivalSubtrees(root1)<<endl;
    cout << s250.p250_countUnivalSubtrees(root2)<<endl;
    cout << s250.p250_countUnivalSubtrees(root3)<<endl;
    cout << s250.p250_countUnivalSubtrees(root4)<<endl;
    cout << s250.p250_countUnivalSubtrees(root5)<<endl;

    cout << "Find Leaves of Binary Tree" << endl;
    Solution366 s366;
    auto r366r1 = s366.p366_findLeaves(root2);
    print2DVector(r366r1);

    cout << "House Robber III" << endl;
    Solution337 s337;
    cout << s337.p337_rob(root1) << endl;
    cout << s337.p337_rob(root2) << endl;
    cout << s337.p337_rob(root3) << endl;
    return 0;

}