class Solution{
  public:
  
  void MergeSorting(Node** head)
  {
      Node* cur= *head;
      Node* first;
      Node* second;
      
      if(!cur or !cur->next)return;
      
      FindMiddle(cur,&first,&second);
      
      //recurse karo left and right sub-LL me
      MergeSorting(&first);
      MergeSorting(&second);
      *head=MergeBoth(first,second);
  }
  
  //slow fast pointer ki madat se nikaala mid point
  void FindMiddle(Node* cur,Node** first,Node** second)
  {
      Node* fast;
      Node* slow;
      slow=cur;
      fast=cur->next;
      
      while(fast!=NULL)
      {
          fast=fast->next;
          if(fast!=NULL)
          {
              slow=slow->next;
              fast=fast->next;
          }
      }
      
      //yaha first is updated with first half of LL and second is updated with second part of LL
      *first=cur;
      *second=slow->next;
      slow->next=NULL;
  }
  
  Node* MergeBoth(Node* first,Node* second)
  {
      Node* answer= NULL;
      
      if(!first)
      {
          return second;
      }
      else if(!second)
      {
          return first;
      }
      
      if(first->data<=second->data)
      {
          answer=first;
          answer->next=MergeBoth(first->next,second);
      }
      else
      {
          answer=second;
          answer->next=MergeBoth(first,second->next);
      }
      
      return answer;
  }
  
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) 
    {
        // your code here
        
        MergeSorting(&head);
        return head;
    
    
        
    }
};
