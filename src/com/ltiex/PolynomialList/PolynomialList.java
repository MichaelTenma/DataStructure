package com.ltiex.PolynomialList;

import com.ltiex.LinkedList.LinkedList;
import com.ltiex.LinkedList.LinkedListNode;

public class PolynomialList extends LinkedList<Polynomial> implements PolynomialListImpl,Cloneable{

	public PolynomialList() {
		super();
	}
	public PolynomialList(Polynomial[] poly) {
		super(poly);
	}

	@Override
	public PolynomialList plus(PolynomialList target) {
		//假设是exponent升序的
		//先找到短的那个list
		PolynomialList minList = this;
		PolynomialList maxList = target;
		if(minList.getLen() > maxList.getLen()) {
			//交换
			PolynomialList temp = minList;
			minList = maxList;
			maxList = temp;
		}
		
		PolynomialList res = new PolynomialList();
		LinkedListNode<Polynomial> minNode = minList.getHead().getNext();
		LinkedListNode<Polynomial> maxNode = maxList.getHead().getNext();
		while(minNode != null) {
			LinkedListNode<Polynomial> tempNode = null;
			if(minNode.equals(maxNode)) {
				minNode.setData(minNode.getData().plus(maxNode.getData()));
				tempNode = minNode;
				minNode = minNode.getNext();
				maxNode = maxNode.getNext();
			}else {
				if(minNode.compareTo(maxNode) < 0) {
					tempNode = minNode;
					minNode = minNode.getNext();
				}else if(minNode.compareTo(maxNode) > 0) {
					tempNode = maxNode;
					maxNode = maxNode.getNext();
				}
			}
			res.addFromTail(tempNode.getData());
		}
		
		while( maxNode != null ) {
			res.addFromTail(maxNode.getData());
			maxNode = maxNode.getNext();
		}
		
		//深克隆返回，避免引用类型数据修改引发的冲突
		return res.clone();
	}

	@Override
	public PolynomialList minus(PolynomialList target) {
		LinkedListNode<Polynomial> node = target.getHead().getNext();
		while(node != null) {
			Polynomial temp = node.getData();
			temp.setCoefficient(-temp.getCoefficient());
			node = node.getNext();
		}
		return this.plus(target).clone();
	}

	@Override
	public PolynomialList mutiply(PolynomialList target) {
		PolynomialList res = new PolynomialList();
		LinkedListNode<Polynomial> thisNode = this.getHead().getNext();
		while(thisNode != null) {
			LinkedListNode<Polynomial> targetNode = target.getHead().getNext();
			while(targetNode != null) {
				Polynomial resPolynomial = thisNode.getData().mutiply(targetNode.getData());
//				System.out.println(resPolynomial);
				if(resPolynomial != null) {
					res.addFromTail(resPolynomial);
				}
				targetNode = targetNode.getNext();
			}
			thisNode = thisNode.getNext();
		}
		
		//整理
		res.sort();
		//合并同类项
		res.mergeExponent();
		return res.clone();
	}
	
	@Override
	public String toString() {
		this.sort();
		StringBuilder res = new StringBuilder();
		LinkedListNode<Polynomial> node = this.getHead().getNext();
		while( node != null ) {
			res.append(node.toString());
			node = node.getNext();
			if(node != null) {
				if(node.getData().getCoefficient() > 0) {
					res.append(" + ");
				}else if(node.getData().getCoefficient() < 0){
					res.append(" - ");
				}
			}

		}
		return res.toString();
	}
	
	@Override
	public PolynomialList clone(){
		PolynomialList res = new PolynomialList();
		LinkedListNode<Polynomial> node = this.getHead().getNext();
		while( node != null ) {
			res.addFromTail(node.getData().clone());
			node = node.getNext();
		}
		return res;
	}
	@Override
	public void sort() {
		//整理PolynomialList，升序且去掉系数为零的Polynomial node
		//去掉系数为零的Polynomial node
		LinkedListNode<Polynomial> preNode = this.getHead();
		LinkedListNode<Polynomial> node = preNode.getNext();
		while( node != null ) {
			if(node.getData().getCoefficient() == 0) {
				preNode.setNext(node.getNext());
				node.setNext(null);
				node = preNode;
			}else {
				preNode = preNode.getNext();
			}
			node = node.getNext();
		}
		
		//reset
		preNode = this.getHead();
		node = preNode.getNext();
		LinkedListNode<Polynomial> tempNode = null;
		//升序排序，冒泡排序
		do {
			LinkedListNode<Polynomial> preMaxNode = preNode;
			LinkedListNode<Polynomial> maxNode = node;
			while(node != null) {
				if(node.compareTo(maxNode) > 0) {
					preMaxNode = preNode;
					maxNode = node;
				}
				preNode = preNode.getNext();
				node = node.getNext();
			}
			//剥离出maxNode
			preMaxNode.setNext(maxNode.getNext());
			maxNode.setNext(null);
			super.setLen(super.getLen()-1);
			//maxNode头插入
			this.addFromHead(maxNode.getData());
			if( tempNode == null ) {
				tempNode = this.getHead().getNext();
			}
			preNode = tempNode;
			node = preNode.getNext();
		}while(node != null);
	}
	
	
	private void mergeExponent() {
		LinkedListNode<Polynomial> preNode = this.getHead();
		LinkedListNode<Polynomial> node = preNode.getNext();
		while(node != null) {
			if(preNode.getData() != null && node.equals(preNode)) {
				preNode.setData(preNode.getData().plus(node.getData()));
				preNode.setNext(node.getNext());
				node.setNext(null);
				this.setLen(this.getLen()-1);
			}else {
				preNode = preNode.getNext();
			}
			node = preNode.getNext();
		}
	}
	
}
