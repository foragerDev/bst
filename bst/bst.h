#pragma once

template<typename compareable>
class tree {
private:
	struct Node {
		compareable n_data;
		Node* n_left;
		Node* n_right;
		
		Node(compareable& data, Node* left, Node* right):
			n_data(data),
			n_left(left),
			n_right(right) {
			//this will return me nothing.
		}
		// node move contructor
		Node(compareable&& data, Node* left, Node* right) : 
			n_data(std::move(data)),
			n_left(left),
			n_right(right) {
			// this will not do anything as well
		}
	};

	Node* root; // root of the tree.

	void insert(const compareable& element, Node*& pos) {
		if (pos == nullptr) {
			pos = new Node(element, nullptr, nullptr);
		}
		if (element < pos->n_data) {
			return insert(element, pos->n_left);
		}
		else if (element > pos->data) {
			return insert(element, pos->n_right);
		}
		else return;
	}

	void insert(compareable&& element, Node*& pos) {
		if (pos == nullptr) {
			pos = new Node(std::move(element), nullptr, nullptr);
		}
		else if (element < pos->n_data) {
			return insert(std::move(element), pos->n_left);
		}
		else if (element > pos->n_data) {
			return insert(std::move(element), pos->n_right);
		}
		else return;
	}
	void remove(const compareable& _element, Node*& pos) {
		if (pos == nullptr) return;

		if (_element < pos->n_data) {
			remove(_element, pos->n_left);
		}
		else if(_element > pos->n_data) {
			remove(_element, pos->n_right);
		}
		else if(pos->n_left != nullptr && pos->n_right != nullptr) {
			Node* temp = get_minimum(pos->n_right);
			pos->n_data = temp->n_data;
			remove(temp->n_data, pos->n_right);
		}
		else {
			Node* old = pos;
			pos = (pos->n_left != nullptr) ? pos->n_left : pos->n_right;
			delete old;
		}
	}
	void clear(Node*& node) {
		if(node == nullptr){
			return;
		}
		clear(node->n_left);
		clear(node->n_right);
		delete node;
		node = nullptr;
	}
	Node* get_minimum(Node* node) const {
		if (node->n_left == nullptr) {
			return node;
		}
		return get_minimum(node->n_left);
	}

	Node* get_maximum(Node* node) const {
		if (node->n_right == nullptr) {
			return node;
		}
		return get_maximum(node->n_right);
	}
	Node* clone_tree(Node* node) {
		if (node == nullptr) {
			return nullptr;
		}
		else {
			return new Node(node->n_data, clone_tree(node->n_left), clone_tree(node->n_right));
		}
	}
public:
	tree() : root(nullptr) {
		//empty contructor
	}

	tree(const tree& copy): root(nullptr) {
		root = clone_tree(copy.root);
	}
	void insert(compareable& element) {
		insert(element, root);
	}
	void insert(compareable&& element) {
		insert(std::move(element), root);
	}
	void remove(const compareable& element) {
		remove(element, root);
	}
	void remove(const compareable&& element) {
		remove(std::move(element), root);
	}
	Node* get_minimum() {
		return get_minimum(root);
	}
	Node* get_maximum() {
		return get_maximum(root);
	}

	~tree() {
		if (root != nullptr) {
			clear(root);
		}
	}
};