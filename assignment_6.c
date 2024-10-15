#include <stdio.h>
#include <stdlib.h>

struct Node {
  int id;
  float gpa;
  struct Node *prev;
  struct Node *next;
};



struct Node *deleteHead(struct Node *head);
struct Node *removeDuplicates(struct Node *head, int id);
struct Node *reverse(struct Node *head);
struct Node *rotateByKplaces(struct Node *head, int k);
struct Node *createSortedList(struct Node *head);
struct Node *addNode(struct Node *rec, struct Node *old) {
  old->next = rec;
  rec->next = NULL;
  rec->prev = old;
  return rec;
}


int main() {
  struct Node *head, *last;
  struct Node *sorted_head;
  head = (struct Node *)malloc(sizeof(struct Node));
  sorted_head = (struct Node *)malloc(sizeof(struct Node));
  head->next = NULL;
  head->prev = NULL;
  // code to take n, k, duplicate_id as input
  int n, k, duplicate_id;
  scanf("%d", &n);
  scanf("%d", &k);
  scanf("%d", &duplicate_id);
  // code to take input n records input and build a dll(4.1)
  for (int i = 0; i < n; i++) {
    struct Node *current;
    current = (struct Node *)malloc(sizeof(struct Node));
    scanf("%d", &current->id);
    scanf("%f", &current->gpa);
    current->next = NULL;
    current->prev = NULL;

    if (i == 0) {
      head = current;
      last = current;
    } else {
      last = addNode(current, last);
    }
    struct Node *curr = head;
    struct Node *tail = head;
    // print head
  }

  head = deleteHead(head);
  head = removeDuplicates(head, duplicate_id);
  head = reverse(head);
  head = rotateByKplaces(head, k);
  sorted_head = createSortedList(head);

  // Do not modify the code below
  struct Node *curr = head;
  struct Node *tail = head;
  // print head
  while (curr != NULL) {
    printf("%d,%.1f->", curr->id, curr->gpa);
    tail = curr;
    curr = curr->next;
  }
  printf("\n");
  // print head in reverse order
  while (tail != NULL) {
    printf("%d,%.1f->", tail->id, tail->gpa);
    tail = tail->prev;
  }
  printf("\n");
  curr = sorted_head;
  tail = curr;
  // print sorted_head in reverse order
  while (curr != NULL) {
    printf("%d,%.1f->", curr->id, curr->gpa);
    tail = curr;
    curr = curr->next;
  }
  printf("\n");
  // print sorted_head in reverse order
  while (tail != NULL) {
    printf("%d,%.1f->", tail->id, tail->gpa);
    tail = tail->prev;
  }
  printf("\n");

  return 0;
}
struct Node *deleteHead(struct Node *head) {
  // Code to delete head from the dll and return new head(4.2)
  struct Node *p;
  p = head -> next;
  p -> prev = NULL;
  head = head->next;
  return head;
}

struct Node *removeDuplicates(struct Node *head, int id) {
  // Code to delete all occurences of the record id and
  // keep only the oldest record with id=id and return new head(4.3)
  // struct Node *present, *past;
  // int x=0,gin = 0, tubhigin = 0;
  // present = head;

  // while(present!=NULL){
  //   if(present->id == id){
  //     x++;
  //   }
  //   present = present->next;
  // }

  // present = head;
  
  
  // while (present != NULL) {
    
  //   if (present->id == id) {
  //     gin++;
  //   }
    

  //   if ((present->id == id) && (gin >= 2)) {

  //       past->next = present->next;
  //     present->next->prev = past;
  //     free(present);

  //     // if(gin == x){
  //     // return head;
  //     // }
  //     // else{}

  //     } else {
  //     past = present;
  //     present= present->next;
  //   }
  // }

  // return head;
  int i=0;
    struct Node *p, * ptr = head;
    while(ptr != NULL)
      {
        if(ptr->id == id)
        {
          p=ptr;
          ptr=ptr->next;
          if(i>0)
          {
            if(p->next != NULL)
            {

              p->next->prev = p->prev;
            }
            if(p->prev != NULL)
            {
              p->prev->next = p->next;
            }
            free(p);

          }
          i++;
        }
        else{
           ptr=ptr->next;
        }
      }


  return head;

}

struct Node *reverse(struct Node *head) {
  // Code to reverse and dll return new head(4.4)
  struct Node *p = head;

  struct Node *q;

  while (p->next != NULL) {
    q = p->next;
    p->next = p->prev;
    p->prev = q;
    p = q;
  }
  p->next = p->prev;
  p->prev = NULL;

  return p;
}

struct Node *rotateByKplaces(struct Node *head, int k) {
  // Code to rotate the dll by k places to the right and return new head(4.5)
  if(k==0){return head;}
  else{
  int i,j;
  struct Node *l,*tail;
  for(i=0;i<k;i++)
    {
      l=head;
      while(l->next != NULL)
        {
          l=l->next;
        }
      if(l==head)
      {
        return head;
      }
      tail = l->prev;
      tail->next= NULL;
      l->next= head;
      head->prev = l;
      l->prev=NULL;
      head= l;
    }

  return head;
  }
}



struct Node *createSortedList(struct Node *head) {
  // Code to create a new dll sorted by gpa (4.6)
  struct Node *p = head;
  struct Node *q = head;
  struct Node *o = head;
  struct Node *nhead, *nlast;
  nhead = (struct Node *)malloc(sizeof(struct Node));
  nhead->next = NULL;
  nhead->prev = NULL;
  int count = 1;
  while (q->next != NULL) {
    count++;
    q = q->next;
  }
  for (int i = 0; i < count; i++) {
    struct Node *current;
    current = (struct Node *)malloc(sizeof(struct Node));
    current->id = o->id;
    current->gpa = o->gpa;
    current->next = NULL;
    current->prev = NULL;
    if (i == 0) {
      nhead = current;
      nlast = current;
    } else {
      nlast = addNode(current, nlast);
    }
    o = o->next;
  }
  p = nhead;
  q = nhead;
  o = nhead;
  while (q->next != NULL) {
    q = q->next;
  }
  p->prev = q;
  q->next = p;
  int flag = 1;
  int stop = 0;
  for (int i = 0; i < count; i++) {
    p = nhead;
    q = p->next;
    stop = 0;
    for (int j = 0; j < count - 1; j++) {
      if (flag == 0 && stop != 0) {
        p = p->next;
        q = q->next;
      }
      if (flag == 1 && stop != 0) {
        q = p->next;
      }
      struct Node *r, *s;
      r = q->next;
      s = p->prev;
      if (q->gpa > p->gpa) {
        s->next = q;
        q->prev = s;
        p->next = r;
        r->prev = p;
        q->next = p;
        p->prev = q;
        flag = 1;
        if (p == nhead) {
          nhead = q;
        }
      } else {
        flag = 0;
      }
      stop++;
    }
  }
  p = nhead;
  o = nhead->prev;
  p->prev = NULL;
  o->next = NULL;

  return nhead;
}
