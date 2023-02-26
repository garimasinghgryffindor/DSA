// iterative 

int len(Node* head)
{
  Node * curr = head;
  int count = 0;
  while(!curr) {
    count++;
    curr = curr->next;
  }
  
  return count;
}



// recursive

int len(Node * head)
{
  if(!head)
    return 0;
  return 1 + len(head->next);
}


