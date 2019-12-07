/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.ltiex.LinkedList;

public class LinkedListNode<DataType extends Comparable<DataType>> implements Comparable<LinkedListNode<DataType>>{

    private DataType data;
    private LinkedListNode<DataType> next;
    
    public LinkedListNode(){
        this(null,null);
    }
    
    public LinkedListNode(DataType data,LinkedListNode<DataType> next){
        this.data = data;
        this.next = next;
    }
    
    public DataType getData() {
        return data;
    }

    public void setData(DataType data) {
        this.data = data;
    }

    public LinkedListNode<DataType> getNext() {
        return next;
    }

    public void setNext(LinkedListNode<DataType> next) {
        this.next = next;
    }
    
    @Override
    public String toString(){
        return String.format("%s",this.data);
    }
    
    public boolean equals(LinkedListNode<DataType> node){
        return this.getData().equals(node.getData());
    }
    
	@Override
	public int compareTo(LinkedListNode<DataType> node) {
		return this.getData().compareTo(node.getData());
	}

}
