#include "deck.h"

int compare_strings(const char *s1, const char *s2);
int get_card_value(deck_node_t *card);
void insertion_sort_deck_by_kind(deck_node_t **deck);
void insertion_sort_deck_by_value(deck_node_t **deck);
void sort_deck(deck_node_t **deck);

/**
 * compare_strings - Compare two strings lexicographically.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 *
 * Return: A positive value if s1 > s2, 0 if s1 == s2, or a negative value if s1 < s2.
 */
int compare_strings(const char *s1, const char *s2)
{
    while (*s1 && *s2 && *s1 == *s2)
    {
        s1++;
        s2++;
    }

    if (*s1 != *s2)
        return (*s1 - *s2);

    return 0;
}

/**
 * get_card_value - Get the numerical value of a card.
 * @card: A pointer to a deck_node_t card.
 *
 * Return: The numerical value of the card.
 */
int get_card_value(deck_node_t *card)
{
    if (compare_strings(card->card->value, "Ace") == 0)
        return 0;
    if (compare_strings(card->card->value, "1") == 0)
        return 1;
    if (compare_strings(card->card->value, "2") == 0)
        return 2;
    if (compare_strings(card->card->value, "3") == 0)
        return 3;
    if (compare_strings(card->card->value, "4") == 0)
        return 4;
    if (compare_strings(card->card->value, "5") == 0)
        return 5;
    if (compare_strings(card->card->value, "6") == 0)
        return 6;
    if (compare_strings(card->card->value, "7") == 0)
        return 7;
    if (compare_strings(card->card->value, "8") == 0)
        return 8;
    if (compare_strings(card->card->value, "9") == 0)
        return 9;
    if (compare_strings(card->card->value, "10") == 0)
        return 10;
    if (compare_strings(card->card->value, "Jack") == 0)
        return 11;
    if (compare_strings(card->card->value, "Queen") == 0)
        return 12;

    return 13;
}

/**
 * insertion_sort_deck_by_kind - Sort a deck of cards by their kind.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_by_kind(deck_node_t **deck)
{
    deck_node_t *current, *insert, *temp;

    for (current = (*deck)->next; current != NULL; current = temp)
    {
        temp = current->next;
        insert = current->prev;

        while (insert != NULL && insert->card->kind > current->card->kind)
        {
            insert->next = current->next;

            if (current->next != NULL)
                current->next->prev = insert;

            current->prev = insert->prev;
            current->next = insert;

            if (insert->prev != NULL)
                insert->prev->next = current;
            else
                *deck = current;

            insert->prev = current;
            insert = current->prev;
        }
    }
}

/**
 * insertion_sort_deck_by_value - Sort a deck of cards by their value.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void insertion_sort_deck_by_value(deck_node_t **deck)
{
    deck_node_t *current, *insert, *temp;

    for (current = (*deck)->next; current != NULL; current = temp)
    {
        temp = current->next;
        insert = current->prev;

        while (insert != NULL &&
               insert->card->kind == current->card->kind &&
               get_card_value(insert) > get_card_value(current))
        {
            insert->next = current->next;

            if (current->next != NULL)
                current->next->prev = insert;

            current->prev = insert->prev;
            current->next = insert;

            if (insert->prev != NULL)
                insert->prev->next = current;
            else
                *deck = current;

            insert->prev = current;
            insert = current->prev;
        }
    }
}

/**
 * sort_deck - Sort a deck of cards by kind and value.
 * @deck: A pointer to the head of a deck_node_t doubly-linked list.
 */
void sort_deck(deck_node_t **deck)
{
    if (deck == NULL || *deck == NULL || (*deck)->next == NULL)
        return;

    insertion_sort_deck_by_kind(deck);
    insertion_sort_deck_by_value(deck);
}

