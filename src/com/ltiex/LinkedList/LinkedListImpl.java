/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.ltiex.LinkedList;

public interface LinkedListImpl<DataType extends Comparable<DataType>> {
    public int getLen();
    public boolean isEmpty();
    public int search(DataType e);
    public void addFromHead(DataType e);
    public void addFromTail(DataType e);
    public boolean insertAt(int index,DataType e);
    public boolean insertAfter(DataType p,DataType e);
    public boolean remove(DataType e);
    public boolean removeAt(int index);
    public LinkedList<DataType> mergeList(LinkedList<DataType> list);
    public DataType get(int index);
}
