/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
LinkedList* ll_newLinkedList(void);//listo
int ll_len(LinkedList* this);//listo
Node* test_getNode(LinkedList* this, int nodeIndex);//listo
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);//listo
int ll_add(LinkedList* this, void* pElement);//listo
void* ll_get(LinkedList* this, int index);//listo
int ll_set(LinkedList* this, int index,void* pElement);//listo
int ll_remove(LinkedList* this,int index);//listo
int ll_clear(LinkedList* this);//listo
int ll_deleteLinkedList(LinkedList* this);//listo

int ll_indexOf(LinkedList* this, void* pElement);
LinkedList* ll_filter(LinkedList* this, int(*pFunc)(void*));
LinkedList* ll_map (LinkedList* this, void*(*pFunc) (void* element));

int ll_isEmpty(LinkedList* this);//listo
int ll_push(LinkedList* this, int index, void* pElement);//listo
void* ll_pop(LinkedList* this,int index);//listo
int ll_contains(LinkedList* this, void* pElement);//Listo
int ll_containsAll(LinkedList* this,LinkedList* this2);//Listo
LinkedList* ll_subList(LinkedList* this,int from,int to);//Listo
LinkedList* ll_clone(LinkedList* this);//listo
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);//listo
