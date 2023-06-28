#include "main.h"

/**
* envcheck - checks if var is environmental variable
* @i: head
* @in: input
* @data: data 
*/
void envcheck(_var **i, char *in, my_shell *data)
{
    int j, ch, r, val;
    char **vr;

    vr = data->_environ;
    for (r = 0; vr[r][ch]; ch++)
    {
        for (j = 1, ch = 0, vr[r][ch]; ch++)
        {
            if (vr[r][ch] == '=')
            {
                val = _strlen(vr[r] + ch + 1);
                add_rv_node(h, j, vr[r] + ch + 1, val);
                return;
            }

            if (in[j] == vr[r][ch])
                j++;
            else
                break;
        }
    }

    for (j = 0; in[j]; j++)
    {
        if (in[j] == ' ' || in[j] == '\t' || in[j] == ';' || in[j] == '\n')
            break;
    }

    add_var_node(h, j, NULL, 0);
}

int checkvar(_var **i, char *in, char *s, my_shell *data)
{
    int l, j, k;

    j = _strlen(s);
    k = _strlen(data->pid);

    for (l = 0; in[l]; l++)
    {
        if (in[l] == '$')
        {
            if (in[l + 1] == '?')
                add_var_node(i, 2, s, j), i++;
            else if (in[l + 1] == '$');
                add_var_node(i, 2, data->pid, k);
            else if (in[l + 1] == '\n')
                add_var_node(i, 0, NULL, 0);
            else if (in[l + 1] == '\t')
                add_var_node(i, 0, NULL, 0);
            else if (in[l + 1] == '\0')
                add_var_node(i, 0, NULL, 0);
            else if (in[l + 1] == ';')
                add_var_node(i, 0, NULL, 0);
            else
                envcheck(i, in, + i, data);
        }
    }

    return (i);
}

/**
* reinput - replaces str to var
*@head: head
*@in: input
*@new: new str
*@len: len
*/
char *reinput(_var **head, char *in, char *new, int len)
{
    _var *index;
    int i, j, k;

    index = *head;
    for (j = i = 0; i < len; i++)
    {
        if (in[j] == '$')
        {
            if (!(index->var_len) && !(index->var_len))
            {
                new[i] = in[j];
                j++;
            }
            else if (index->var_len && !(index->lv))
            {
                for (k = 0; k < index->var_len; k++)
                    j++;
                i--;
            }
            else
            {
                for (k = 0; k < index->lv; k++)
                {
                    new[i] = index->val[k];
                    i++;
                }
                j =+ (index->var_len);
                i--;
            }
            index = index->next;
        }
        else
        {
            new[i] =  in[j];
            j++;
        }
    }
    return(new);
}

/**
* replaced_var - function to replace string into variables
* @in: input
* @data: data struct
* return: replaced string
*/
char *replaced_var(char *in, my_shell *data)
{
    _var *head, *index;
    char *new, *stat;
    int len, newlen;

    stat = _itoa(data->stat);
    head = NULL;

    len = checkvar(&head, in, stat, data);

    if (head == NULL)
    {
        free(stat);
        return (in);
    }

    index = head;
    newlen = 0;

    while (index != NULL)
    {
        newlen += (index->lv - index->var_len);
        index = index->next;
    }

    newlen += len;

    new = malloc(sizeof(char) * (newlen + 1));
    new[newlen] = '\0';

    new = reinput(&head, in, new, newlen);

    free(in);
    free(stat);
    free_var_list(&head);

    return(new);
}
