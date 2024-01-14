  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>

  typedef struct st
  {
    int id;
    struct st *next;
  } Node;

  Node *root = NULL;

  Node * get_node(int id)
  {
      Node *node;
      node = malloc (sizeof (Node));
      if (node == NULL)
      {
          printf ("Unable to allocate memory\n");
          return NULL;
      }
      else
      {
          node->id = id;
          node->next = NULL;
      }
      return node;
  }

  void print_data ()
  {
    Node *temp = root;
    while (temp != NULL)
    {
      printf ("%d ", temp->id);
      temp = temp->next;
    }
    printf ("\n");
  }

  void reverse_recursively(Node *ptr)
  {
    if (ptr->next == NULL)
    {
      root = ptr;
      return;
    }
    reverse_recursively(ptr->next);
    Node *temp = ptr->next;
    temp->next = ptr;
    ptr->next = NULL;

  } 
  
  void add_node_at_first (int id)
  {
    Node *node;
    node = malloc (sizeof (Node));
    if (node == NULL)
    {
      printf ("Unable to allocate memory\n");
      return;
    }
    else
    {
      node->id = id;
      node->next = NULL;
    }
    if (root == NULL)
    {
      root = node;
    }
    else
    {
      node->next = root;
      root = node;
    }
  }

  void add_node_at_last (int id)
  {
    Node *node;
    node = malloc (sizeof (Node));
    if (node == NULL)
    {
      printf ("Unable to allocate memory\n");
      return;
    }
    else
      {
        node->id = id;
        node->next = NULL;
      }
    if (root == NULL)
      {
        root = node;
      }
    else
      {
        Node *temp = root;

        while (temp->next != NULL)
    {
      temp = temp->next;
    }
        temp->next = node;
      }
  }

  void delete_at_first ()
  {
    Node *temp = root;
    if (temp == NULL)
      printf ("\nNo data present\n");
    else
      {
        root = root->next;
        temp->next = NULL;
        free (temp);
      }
  }

  void delete_at_last ()
  {
      Node *prev = NULL, *temp = root;
      if (temp == NULL)
      {
          printf ("\nNo data present\n");
      }
      else
      {
          while (temp->next != NULL)
          {
            prev = temp;
            temp = temp->next;
        }
          if(prev == NULL)
            root = NULL;
          else
              prev->next = NULL;
          
          free (temp);
      }
  }

  void add_at_middle(int id)
  {
      Node *node;
      node = malloc (sizeof (Node));
      if (node == NULL)
      {
          printf ("Unable to allocate memory\n");
          return;
      }
      else
      {
          node->id = id;
          node->next = NULL;
      }

      if(root == NULL)
      {
          root = node;
      }
      else
      {
          Node *prev = root, *temp = root->next;
          
          while(temp && temp->next)
          {
              prev = prev->next;
              temp = temp->next->next;
          }
          node->next = prev->next;
          prev->next = node;
      }
  }

  void delete_at_middle()
  {
      if (root == NULL)
      {
        printf("No data to print\n");
        return;
      }
      else
      {
        if (root->next == NULL)
        {
            free(root);
            root = NULL;
        }
        else
        {
          Node *temp = root->next, *mid = root, *prev;
          while (temp && temp->next != NULL)
          {
              prev = mid;
              mid = mid->next;
              temp = temp->next->next;
          }
          prev->next = mid->next;
          free(mid);
        }
      }   
  }

  void add_at_nth_position(int data, int position)
  {
    Node * new_node =  malloc(sizeof(Node));

    if (new_node == NULL)
    {
      printf("Unable to allocate memory\n");
      return;
    }
    else
    {
      new_node->id = data;
      new_node->next = NULL; 
      if(root == NULL)
      {
        root = new_node;
      }
      else
      {
        if (position == 1)
        {
          new_node->next = root;
          root = new_node;
        }
        else
        {
          Node *temp = root, *temp2;
          for (int i = 0; i < position - 2; i++)
          {
            temp = temp->next;
          }
          temp2 = temp->next;
          temp->next = new_node;
          new_node->next = temp2;
        }
      }
    }
  }

  void delete_at_nth_position(int position)
  {
    if (root == NULL)
    {
      printf("No data to print\n");
    }
    else
    {
      if (position == 1)
      {
          Node *temp = root;
          root = root->next;
          free(temp);
      }
      else
      {
        Node *temp = root, *temp2;
        for (int i = 0; i < position - 2; i++)
        {
          temp = temp->next;
        }
        temp2 = temp->next;
        temp->next = temp->next->next;
        free(temp2);
      }
    }
  }

  void reverse_list()
  {
    if (root == NULL)
    {
      printf("No data is present\n");
    }
    else
    {
      if (root->next == NULL)
      {
        return;
      }
      else
      {
          Node *next = NULL, * curr = root, *prev = NULL;
          while (curr)
          {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
         }
          root = prev;
        }      
    }    
  }


  int main ()
  {
      /*int arr[3][3] = {   {11, 12, 13},
      {14, 15, 16},
      {17, 18, 19}};

      //printf("arr[1][1] = %d\n", arr[1][1]);
      //printf("(*(*arr + 1 ) + 1) = %d\n", *(*(arr + 1) + 1));

      for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++)
      printf("%d ", arr[i][j]);
      printf("\n--------------------------------------\n");
      for(int i = 0; i < 3; i++)
      for(int j = 0; j < 3; j++)
      printf("%d ", *( *(arr + i) + j)); */
      add_node_at_first(6);
      add_node_at_first(5);
      add_node_at_first(4);
      add_node_at_first(3);
      add_node_at_first(2);
      add_node_at_first(1);
      print_data();
      reverse_recursively(root);
      print_data();
      return 0;
  }
