/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.ltiex.LinkedList;

public class LinkedList<DataType extends Comparable<DataType>> implements LinkedListImpl<DataType>{
	private LinkedListNode<DataType> head;
    private LinkedListNode<DataType> tail;
    private int len;
    
    public LinkedList(){
        this.head = new LinkedListNode<>();
        this.tail = this.head;
        this.len = 0;
    }
    
    public LinkedList(DataType data[]){
        this();
        for(int i = 0;i < data.length;i++){
            this.addFromTail(data[i]);
        }
        this.len = data.length;
    }

    @Override
    public boolean isEmpty() {
        return this.len <= 0;
    }

    @Override
    public int search(DataType e) {
        LinkedListNode<DataType> node  = this.head.getNext();
        int index = -1;
        while(node != null){
            index++;
            if(node.equals(e)){
                break;
            }
            node = node.getNext();
        }
        return index;
    }

    @Override
    public boolean insertAt(int index, DataType e) {
        boolean res = false;
        if(index >= 0 && index <= this.getLen()){
            LinkedListNode<DataType> p = this.head;
            for(int i = 0;i < index;i++){
                p = p.getNext();
            }
            LinkedListNode<DataType> target = new LinkedListNode<>(e,p.getNext());
            p.setNext(target);
            
            this.len++;
            res = true;
        }
        return res;
    }

    @Override
    public boolean insertAfter(DataType p, DataType e) {
        boolean res = false;
        LinkedListNode<DataType> node = this.head.getNext();
        LinkedListNode<DataType> targetNode = new LinkedListNode<DataType>(p,null);
        while( node != null ) {
        	if(node.equals(targetNode)) {
        		node.setNext(new LinkedListNode<DataType>(e,node.getNext()));
        		res = true;
        		break;
        	}
        	node = node.getNext();
        }
        return res;
    }

    @Override
    public boolean remove(DataType e) {
        boolean res = false;
        LinkedListNode<DataType> preNode = this.head;
        LinkedListNode<DataType> node = preNode.getNext();
        while(node != null){
            if(node.equals(e)){
                preNode.setNext(node.getNext());
                node.setNext(null);
                res = true;
                break;
            }
            preNode = node;
            node = preNode.getNext();
        }
        return res;
    }

    @Override
    public boolean removeAt(int index) {
        boolean res = index >= 0 && index < this.getLen();
        if(res){
            LinkedListNode<DataType> preNode = this.head;
            LinkedListNode<DataType> node = preNode.getNext();
            for(int i = 0;i < index;i++){
                preNode = node;
                node = preNode.getNext();
            }
            preNode.setNext(node.getNext());
            node.setNext(null);
        }        
        return res;
    }

    @Override
    public DataType get(int index) {
        DataType res = null;
        if(index >= 0 && index < this.getLen()){
            LinkedListNode<DataType> p = this.head.getNext();
            for(int i = 0;i <= index;i++){
                p = p.getNext();
            }
            res = p.getData();
        }
        return res;
    }

    @Override
    public final void addFromHead(DataType e) {
        LinkedListNode<DataType> target = new LinkedListNode<>(e,this.head.getNext());
        if(this.getLen() == 0){
            this.tail = target;
        }
        this.head.setNext(target);
        this.len++;
    }
    
    @Override
    public void addFromTail(DataType e) {
        LinkedListNode<DataType> node = new LinkedListNode<>(e,null);
        this.tail.setNext(node);
        this.tail = node;
        this.len++;
    }

    @Override
    public int getLen() {
        return this.len;
    }
    
    protected LinkedListNode<DataType> getHead() {
		return head;
	}

	protected void setHead(LinkedListNode<DataType> head) {
		this.head = head;
	}

	protected LinkedListNode<DataType> getTail() {
		return tail;
	}

	protected void setTail(LinkedListNode<DataType> tail) {
		this.tail = tail;
	}

	protected void setLen(int len) {
		this.len = len;
	}
    
    @Override
    public String toString(){
        StringBuilder res = new StringBuilder();
        LinkedListNode<DataType> p = this.head.getNext();
        while(p != null){
            res.append(p).append(",");
            p = p.getNext();
        }
        return res.toString();
    }

    @Override
    public LinkedList<DataType> mergeList(LinkedList<DataType> list) {
        //找到长度最小的一个list，minList maxList
        LinkedList<DataType> minList = this;
        LinkedList<DataType> maxList = list;
        if(minList.getLen() > maxList.getLen()){
            //交换
        	System.out.println("交换");
            LinkedList<DataType> temp = minList;
            minList = maxList;
            maxList = temp;
        }
        
        LinkedList<DataType> res = new LinkedList<>();
        LinkedListNode<DataType> aNode = minList.head.getNext();
        LinkedListNode<DataType> bNode = maxList.head.getNext();
        while(aNode != null){
            if(aNode.compareTo(bNode) <= 0){
                res.addFromTail(aNode.getData());
                aNode = aNode.getNext();
            }else{
                res.addFromTail(bNode.getData());
                bNode = bNode.getNext();
            }
        }
        
        while(bNode != null){
            res.addFromTail(bNode.getData());
            bNode = bNode.getNext();
        }
        
        //copy
        return res;
    }

}
