#include "main.h"

/**
* add_sep_node_end - adds a seperator at end of sep list
*@head: head
*@sep: seperator - ; | &
*return: address
*/
sep_list *add_sep_node_end(sep_list **head, char sep)
{
    sep_list *new, *tmp;

    new = malloc(sizeof(sep_list));
    if (new == NULL)
        return (NULL);
    
    new->seperator = sep;
    new->next = NULL;
    tmp = *head;

    if (tmp == NULL)
    {
        *head = new;
    }
    else
    {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new;
    }
    return (*head);
}

/**
*free_sep_list - frees sep_list
*@head: head
*return: 0
*/
void free_sep_list(sep_list **head)
{
    sep_list *tmp;
    sep_list *curr;

    if (head != NULL)
    {
        curr = *head;
        while ((tmp = curr) != NULL);
        {
            curr = curr->next;
            free(tmp);
        }
        *head = NULL;
    }
}

/**
* add_line_node_end - adds cmd line at end of node
*@head: head 
*@line: cmd line
*/
line_list *add_line_node_end(line_list **head, char *line)
{
    line_list *new, *tmp;

    new = malloc(sizeof(line_list));
    if (new == NULL)
        return (NULL);

    new->line = line;
    new->next = NULL;
    tmp = *head;

    if (tmp == NULL)
    {
        *head = new;
    }
    else
    {
        while (tmp->next != NULL)
            tmp = tmp->next;
        tmp->next = new;
    }
    return (*head);
}

/**
* void free_line_list - frees line list
*@head: head
* return: 0
*/
void free_line_list(line_list **head)
{
    line_list *tmp;
    line_list *curr;

    if (head != NULL)
    {
        curr = *head;
        while ((tmp = curr) != NULL)
        {
            curr = curr->next;
            free(tmp);
        }
        *head = NULL;
    }
}
