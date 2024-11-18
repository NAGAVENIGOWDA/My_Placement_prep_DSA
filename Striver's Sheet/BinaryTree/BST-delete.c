#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *rlink;
	struct node *llink;
}NODE;

void insert(NODE **root,int ele)
{
	NODE *temp=malloc(sizeof(NODE));
	temp->data=ele;
	temp->rlink=temp->llink=NULL;
	if(*root==NULL)
	{   
		*root=temp;
		return;
	}
	NODE *cur=*root;
	NODE *prev=NULL;
	while(cur!=NULL)
	{
		prev=cur;
		if(ele<cur->data)
			cur=cur->llink;
		else
			cur=cur->rlink;
	}
	if(ele<prev->data)
		prev->llink=temp;
	else
		prev->rlink=temp;
}

void preorder(NODE *root)
{
	if(root==NULL)
		return;
	printf("%d\t",root->data);
	preorder(root->llink);
	preorder(root->rlink);
}

void inorder(NODE *root)
{
	if(root==NULL)
		return;
	inorder(root->llink);
	printf("%d\t",root->data);
	inorder(root->rlink);
}

void postorder(NODE *root)
{
	if(root==NULL)
		return;
	postorder(root->llink);
	postorder(root->rlink);
	printf("%d\t",root->data);
}

NODE *search_ele(NODE *root,int ele)
{
	NODE *cur=root;
	if(cur==NULL)
		return(cur);
	while(cur!=NULL)
	{
		if(ele==cur->data)
			return(cur);
		if(ele<cur->data)
			cur=cur->llink;
		else
			cur=cur->rlink;
	}
	return NULL;
}

/*NODE *search_ele(NODE *root,int ele)
{
	if(root==NULL ||root->data==ele)
		return root;
	if(ele<root->data)
		return(search_ele(root->llink,ele));
	return(search_ele(root->rlink,ele));
}  
*/
NODE *max_ele(NODE *root)
{
	NODE *cur=root;
	while(cur->rlink!=NULL)
	{
		cur=cur->rlink;
	}
	return(cur);
}

NODE *delete(NODE *root,int ele)
{
	NODE *prev=NULL,*succ,*q;
	if(root==NULL)
	{
		return NULL;
	}
	NODE *cur=root;
	while(cur!=NULL)
	{   prev=cur;
		
		if(ele==cur->data)   //searching for a number which has to be deleted
			break;
	   
		if(ele<cur->data)
			cur=cur->llink;
		else
			cur=cur->rlink;
	}

	if(cur==NULL)
	{
		printf("Element not found\n");
		return(root);  //
	}
	if(cur->llink==NULL)
	{
		q=cur->rlink;
	}
	else if (cur->rlink==NULL)
		q=cur->llink;
	else{
		NODE* p = NULL;
        NODE* succ;
 
        
        succ = cur->rlink;
        while (succ->llink != NULL) 
		{
            p = succ;
            succ = succ->llink;
        }        
        if (p != NULL)
            p->llink = succ->rlink; 
        
        else
            cur->rlink = succ->rlink;
		
        cur->data = succ->data;
		
        free(succ);
		return(root);
    }
		
	
	if(prev==NULL)  //root
	{
		printf("%d is deleted\n",cur->data);
		free(cur);
		return(q);
	}
	if(cur==prev->llink)
		prev->llink=q;
	else
		prev->rlink=q;	
	printf("%d is deleted\n",cur->data);
	free(cur);
	return(root);
}
	
		
		
	
	

	
		
	
		
	
	
		
	
	
		
	
int main()
{
	NODE *root=NULL;
	int ele,ch,x;
	NODE *search=NULL;
	NODE *max=NULL;
	while(1)
	{
		printf("1.insert\n 2.search\n 3.preorder\n 4.inorder\n 5.postorder\n 6.MAX element");
		printf("enter your choice\n");
		scanf("%d",&ch);
		NODE *tmp;
		switch(ch)
		{
			case 1: printf("Enter the element\n");
					scanf("%d",&ele);
					insert(&root,ele);
					break;
			case 2:printf("Enter the key element\n");
					scanf("%d",&ele);
					search=search_ele(root,ele);
					if(search==NULL)
						printf("Not found");
					else
						printf("%d is found",search->data);
					break;
						
			case 3:preorder(root);
			break;
			case 4:inorder(root);
			break;
			case 5: postorder(root);
			break;
			case 6:max= max_ele(root);
					printf("Max element=%d\n",max->data);
					break;
			case 7:printf("Enter the element to be deleted\n");
				   scanf("%d",&ele);
				   root=delete(root,ele);
				   break;
				   
		}
	}
	return(0);
}