#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

void addTail(ListNode **head, int value){
	ListNode *newListNode = new ListNode(value);

	if (!*head){
		*head = newListNode;
	}
	else{
		ListNode *temp = *head;
		while (temp->next){
			temp = temp->next;
		}
		temp->next = newListNode;
	}
}

class Solution{
public:
	void exchange(int &a, int &b){
		int temp;
		temp = a;
		a = b;
		b = temp;
	}
	ListNode* Partition(ListNode *A, ListNode *p, ListNode *r){
		ListNode *i, *j;
		i = p;// i point to head %% i = NULL;
		// j = p;//%% j point to the first node
		int temp = r->val;
		for (j = p->next; j != r; j = j->next){
			if (j->val < temp){
				/*if (i == NULL){
					i = p;
				}
				else{
					i = i->next;
				}*/
				exchange(i->next->val, j->val); //exchange(i->val, j->val);
				i = i->next;
			}
		}
		exchange(i->next->val, r->val);
		return i;// i->next;
	}

	void quickSort(ListNode *A, ListNode *p, ListNode *r){
		if (p != r){
			ListNode *q;
			q = Partition(A, p, r);
//			if (q == NULL)
//				quickSort(A, p->next, r);
//			else if (q!=p)
				quickSort(A, p, q);
//			if (q!=NULL&&q->next!=NULL)
				quickSort(A, q->next, r);
		}
	}

	ListNode *sortList(ListNode *head){

		if (head == NULL){
			return head;
		}
		ListNode *p_begin, *p_end;//p_begin:p p_end:r
		p_begin = head;
		p_end = head;
		while (p_end->next){
			p_end = p_end->next;
		}
//		printf("%d", p_end->val);
		quickSort(head, p_begin, p_end);

		return head;
	}
};

int main(){
	int lt = time(NULL);
	srand(lt);
	int len = rand() % 20;
	cout << len << endl;
	//ListNode *root = NULL;
	ListNode *root = new ListNode(0);//head point's value is 0
	if (len < 1){
		return 0;
	}
	else{
		for (int i = 0; i < len; i++){
			addTail(&root, rand()%100);
		}
	}
	
	ListNode *p = root;
	while (p->next){
		p = p->next;
		printf("%d ", p->val);
	}
	printf("\n");
	ListNode *res;
	Solution s;
	res=s.sortList(root);

	ListNode *r = res;
	while (r->next){
		printf("%d ", r->next->val);
//		printf("%d\n", r->val);
		r = r->next;
	}
	printf("\n");
	system("pause");
	return 0;
}