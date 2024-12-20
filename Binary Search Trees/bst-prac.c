#include "_header.h"

// * FUNCTION DEFINITIONS HERE
void Initialize(BSTPtr *B) {
  *B = NULL;
}

void Preorder(BSTPtr B){
  print("%d", B->data);

  if(B->left != NULL) Preorder(B->left);

  if(B->right != NULL) Preorder(B->right);
}

void Postorder(BSTPtr B) {
  if(B->left != NULL) Preorder(B->left);

  if(B->right != NULL) Preorder(B->right);

  print("%d", B->data);
}

void Inorder(BSTPtr B) {
  if(B->left != NULL) Preorder(B->left);
   
   print("%d", B->data);

  if(B->right != NULL) Preorder(B->right);
}

    
void Insert(BSTPtr *B, node N) {
  BSTPtr *trav, temp = (BSTPtr)malloc(sizeof(struct node));

  for(trav = B; *trav != NULL;){
    if(N < (*trav)->data){
      trav = &(*trav)->left;
    } else {
      trav = &(*trav)->right;
    }
  }

  temp->data = N;
  temp->left = NULL;
  temp->right = NULL;
  *trav = temp;
}

void Delete(BSTPtr *B, int node) {
  for(; *B != NULL;){
      if(node < (*B)->data){
      B = &(*B)->left;
    } else {
      B = &(*B)->right;
    }
  }

  if(*B != NULL){
    BSTPtr *trav, temp;
    if((*B)->right != NULL) {
      for(trav = &(*B)->right; *trav != NULL; trav = &(*trav)->left){}
      temp = *trav;
      (*B)->data = temp->data;
      *trav = (*trav)->right;
    } else {
      temp = *B;
      *B = (*B)->left;
    }
  } else {
    print("Node not found");
  }
}

Boolean Member(BSTPtr B, node N) {
   for(; B != NULL && B->data != N;){
      if(B->data > N){
        B = B->left;
      } else {
        B = B->right;
      }
   }

   return B == NULL ? FALSE : TRUE;
}
    
node Min(BSTPtr B) {
   for(; B != NULL && B->left != NULL;  B = B->left){}

  return B->data;
}

node Max(BSTPtr B) {
  for(; B != NULL && B->right != NULL;  B = B->right){}

  return B->data;
}

int main()
{
    BSTPtr myBST;
    int mySet[] = {15, 13, 18, 19, 5, 14, 4, 10, 7, 2, 12, 3};

    //Initialize my BST;
    Initialize(&myBST);

    //Insert into my BST
    int x;
    for (x = 0; x < 12; ++x) {
        Insert(&myBST, mySet[x]);
    }

    //Display Preorder
    Preorder(myBST);
    // printf("%d", myBST->data);

    //Delete from my BST
    Delete(&myBST, 15);

    //Display updated BST
    printf("\nPREORDER\n");
    Preorder(myBST);
    printf("\nPOSTORDER\n");
    Postorder(myBST);
    printf("\nINORDER\n");
    Inorder(myBST);

    // //Checking to see if my Member function worked
    printf("\n[%d] => %s", Member(myBST, 19), Member(myBST, 23) == TRUE ? "True" : "False");

    // //Finding out what are the highest and lowest values
    printf("\nLOWEST: [%d]...\tHIGHEST:[%d]...\n", Min(myBST), Max(myBST));
    return 0;
}