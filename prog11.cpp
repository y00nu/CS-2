// Mar, 3 2020
// Binary Search Tree
#include <iostream>

using namespace std;

class TNode{
    private:
        TNode* parent;
        TNode* left;
        TNode* right;
        int storage;
    public:
		// Good to have the value element first (not like Tnode, int)
        TNode(int x = 0, TNode* p = NULL, TNode* l = NULL, TNode* r = NULL){ 
           storage = x;
		   parent = p;
		   left = l;
		   right = r;
        }
        TNode* getParent(){
            return parent;
        }
        void setParent(TNode* x){
            parent = x;
        }
        TNode* getLeft(){
            return left;
        }
        void setLeft(TNode* x){
            left = x;
        }
        TNode* getRight(){
            return right;
        }
        void setRight(TNode* x){
            right = x;
        }
        int getStorage(){
            return storage;
        }
        void setStorage(int x){
            storage = x;
        }

};

// Everything left is less than the parent node, everything right is larger than the parent node.
class BSTree{
	private:
		TNode* root;
		int nbOfNode;
		void prePrint(TNode* ptr){
			if(ptr!=NULL){
				prePrint(ptr->getLeft());
				cout << ptr->getStorage() << endl;
				prePrint(ptr->getRight());
			}
		}
	public:
		BSTree(int x = 0, TNode* y = NULL){
			nbOfNode = x;
			root = y;
		}
		void setRoot(TNode* x){ root = x;}
		TNode* getRoot(){ return root; }
		void setnbOfNode(int x){ nbOfNode = x; }
		int getnbOfNode(){ return nbOfNode; }
		
		void add(int x){
			// Nothing in the tree
			if(nbOfNode  == 0){
				root = new TNode(x);
				nbOfNode++;
			}
			else{
				TNode* temp = root;
				for (int i = 0; i < nbOfNode; i++)
				{
					// Check left
					if(x < temp->getStorage()){
						if(temp->getLeft() == NULL){
							TNode* newNode = new TNode(x, temp);
							temp->setLeft(newNode);
							nbOfNode++;
							break;
						}
						else{
							temp = temp->getLeft();
						}
					}
					// Check right
					else{
						if(temp->getRight() == NULL){
							TNode* newNode = new TNode(x, temp);
							temp->setRight(newNode);
							nbOfNode++;
							break;
						}
						else{
							temp = temp->getRight();
						}
					}
				}
				
			}
		}
		void remove(int x){}
		// TNode* search(int x){}
		void print(){
			prePrint(root);
		}
};

int main(){
    BSTree tree;

	tree.add(300);
	tree.add(200);
	tree.add(500);
	tree.add(250);
	tree.add(275);

	tree.print();
    return 0;    
}