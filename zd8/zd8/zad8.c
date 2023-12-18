#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node node;
typedef struct node* position;
struct node {
	int el;
	position left;
	position right;


};
position createnode(int el);
position insert(position root, int el);
int inorder(position root);
int preorder(position root);
int postorder(position root);
position searchnode(position root, int el);
position deletenode(position root, int el);
position findmin(position root);

int main() {
	
	int rootEl = 0;
	position root = NULL;
	int choice;

	printf("Unesi vrijednost root-a:\n");
	scanf("%d", &rootEl);
	root = insert(root, rootEl);
	while (1) {
		printf("\nOdaberite:\n 1-unos novog elementa\n2-inorder ispis\n3-preorder ispis\n4-postorder ispis\n5-pretrazivanje elementa\n6-brisanje elementa iz stabla\n ");
		scanf("%d", &choice);

		if (choice == 1) {
			int el = 0;
			printf("Unesi vrijednost\n");
			scanf("%d", &el);
			root = insert(root, el);
		}

		else if (choice == 2) {
			printf("Inorder ispis:\n");
			root = inorder(root);

		}
		else if (choice == 3) {
			printf("Preorder ispis:\n");
			root = preorder(root);

		}
		else if (choice == 4) {
			printf("Postorder ispis:\n");
			root = postorder(root);

		}
		else if (choice == 5) {
			int el = 0;
			printf("Unesite vrijednost koju trazite:");
			scanf("%d", &el);
			position result = 0;
			result = searchnode(root, el);
			if (result != NULL)
				printf("Pronaden je element: %d\n", el);
			else
				printf("Trazeni element ne postoji\n");

		}
		else if (choice == 6) {
			int el = 0;
			printf("Unesi element kojeg zelis izbrisati:");
			scanf("%d", &el);
			root = deletenode(root, el);

		}
		else
			printf("Pogresan unos!!\n");
		
	}
	return 0;

}
position createnode(int el) {
	position newnode = NULL;
	newnode = (position)malloc(sizeof(struct node));
	if (newnode == NULL) {
		printf("Greska pri alociranju memorije!\n");
		return NULL;
	}
	newnode->el = el;
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode;
}
position insert(position root, int el) {
	if (root == NULL) {
		root = createnode(el);
	}
	else if (el < root->el) {
		root->left = insert(root->left, el);
	}
	else if (el > root->el) {
		root->right = insert(root->right, el);
	}
	return root;
}
int inorder(position root) {
	if (root != NULL) {
		root->left = inorder(root->left);
		printf("%d ", root->el);
		root->right = inorder(root->right);
	}
	return 0;
}

int preorder(position root) {
	if (root != NULL) {
		printf("%d ", root->el);
		root->left = preorder(root->left);
		root->right = preorder(root->right);

	}
	return 0;
}
int postorder(position root) {
	if (root != NULL) {
		root->left = postorder(root->left);
		root->right = postorder(root->right);
		printf("%d ", root->el);
	} 
	return 0;

}
position searchnode(position root, int el) {
	if (root == NULL) {
		return root;
	}
	else if (el < root->el) {
		return searchnode(root->left, el);
	}

	else if (el > root->el) {
		return searchnode(root->right, el);
	}
	else
		return root;
}

position deletenode(position root, int el) {
	if (root == NULL) {
		return NULL;
	}
	else if (el < root->el) {
		root->left = deletenode(root->left, el);
	}

	else if (el > root->el) {
		root->right = deletenode(root->right, el);
	}
	else {
		if (root->left == NULL) {
			position temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			position temp = root->left;
			free(root);
			return temp;
		}

		position temp = findmin(root->right);
		root->el = temp->el;
		root->right = deletenode(root->right, temp->el);
	}
	return root;
}
position findmin(position root) {
	if (root == NULL) {
		return NULL;
	}
	else {
		if (root->left == NULL) {
			return root;
		}
		else {
			return findmin(root->left);
		}
	}
}
