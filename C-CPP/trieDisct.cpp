#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h> 
  
  
#define convert(c) ((int)c - (int)'a') 


struct Trie 
{ 
	Trie *children[26];
	Trie *parent;
  	char meaning[20];
	bool end; 
}*root=NULL,*curr=NULL,*temp=NULL; 
  
Trie *createNode() 
{ 
	Trie *node=NULL;
    node = (struct Trie *)malloc(sizeof(struct Trie));
    node->parent=NULL;
    if (node) 
    { 
        int i; 
  
        node->end = false; 
  
        for (i = 0; i < 26; i++) 
            node->children[i] = NULL; 
    }
    
    return node; 
} 
  
void insert(Trie *root, const char *key, char meaning[]) 
{ 
    int length = strlen(key); 
    int index; 
  
    curr = root; 
  
    for (int level = 0; level < length; level++) 
    { 
        index = convert(key[level]); 
        if (!curr->children[index]) {
            curr->children[index] = createNode(); 
		}
		temp=curr->children[index];
        temp->parent=curr;
        curr=temp;
    } 
  
    curr->end = true; 
    strcpy(curr->meaning,meaning);
} 
  
void search(Trie *root, const char *key){ 
    int length = strlen(key); 
    int index; 
    char str[20];
    curr = root; 
  	
    for (int level = 0; level < length; level++){ 
        index = convert(key[level]);
        
        if (!curr->children[index]) {
        	printf ("Not found\n");
            return; 
		}
        curr = curr->children[index]; 
    }
    if (curr->end)
  		printf ("meaning : %s\n",curr->meaning);
  	else printf("Not found\n");
}



bool checkEmpty(Trie* root) 
{ 
    for (int i = 0; i < 26; i++) 
        if (root->children[i]) 
            return false; 
    return true; 
}
Trie *delet(Trie* root, char key[], int depth){ 
    if (!root) 
        return NULL;
        
    if (depth == strlen(key)) {
        if (root->end) 
            root->end = false;
            
        if (checkEmpty(root)) { 
            free (root); 
            root = NULL; 
        }
        return root;
    }
    
    int index = convert(key[depth]);
    root->children[index]=delet(root->children[index], key, depth + 1);

    if (checkEmpty(root) && root->end == false) {
        free (root);
        root = NULL;
    }
    
    return root; 
}

int main() 
{ 
    Trie *root = createNode(); 
    int input;
    char en[20],in[20];
  	do {
  		printf ("English to Indonesia Dictionary\n");
  		printf ("===============================\n");
  		printf ("1. Insert\n2. Delete\n3. Search\n4. Exit\n>> ");
  		scanf ("%d",&input);
  		
  		switch (input){
  			case 1:
  				printf ("Enter new word in english: ");
  				scanf ("%s",&en);
  				printf ("Enter new word meaning: ");
  				scanf ("%s",&in);
  				insert(root,en,in);
  				printf ("\nInsert %s success\n\n",en);
  				break;
  			case 2:
  				printf ("Enter word to delete : ");
  				scanf ("%s",&en);
  				delet(root,en,0);
  				printf ("\nDelete %s success\n\n",en);
  				break;
  			case 3:
  				printf ("Enter word in english : ");
  				scanf ("%s",&en);
  				printf ("\nWord : %s\n",en);
  				search(root,en);
  				printf ("\n");
  				break;
		}
	}while (input !=4);
	
	
    return 0; 
} 
