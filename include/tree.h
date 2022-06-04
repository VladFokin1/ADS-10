// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_
#include <algorithm>
#include <string>
#include <vector>


class Tree {
 private:
    struct Node {
      char value;
      std::vector <Node*> childs;
    };
    Node* root;
    
    void createTree(Node* root, std::vector<char> numbers) {
      if (!numbers.size()) {
        return;
      }
      if (root->value != '*') {
        numbers.erase(std::find(numbers.begin(), numbers.end(), root->value));
      }
      for (int i = 0; i < numbers.size(); i++) {
        root->childs.push_back(new Node);
      }
      for (int i = 0; i < root->childs.size(); i++) {
        root->childs[i]->value = numbers[i];
        createTree(root->childs[i], numbers);
      }
    }
    
    std::vector<std::vector<char>> allPermutations;
  
    void countAllPermutations(Node* root) {
      std::vector<char> res;
      if (root->value != '*') {
        res.push_back(root->value);
      }
      if (!root->childs.size()) {
        allPermutations.push_back(res);
        return;
      }
      for (int i = 0; i < root->childs.size(); i++) {
        countAllPermutations(root->childs[i], res);
      }
    }

 public:
    std::vector<char> getPermutation(int i) {
      if (i >= allPermutations.size()) return "";
      return allPermutations[i];
    }
    Tree(std::vector<char> input) {
      root = new Node();
      root->value = '*';
      createTree(root, input);
      countAllPermutations(root);
    }
}
#endif  // INCLUDE_TREE_H_
