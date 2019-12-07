package com.ltiex.PolynomialList;

public class Polynomial implements Comparable<Polynomial>,Cloneable{


	private int exponent;//次方
	private int coefficient;//系数
	private char unknown;//元
	
	public Polynomial() {
		this(0,0);
	}
	
	public Polynomial(int coefficient,int exponent) {
		this.coefficient = coefficient;
		this.exponent = exponent;
		this.unknown = 'x';
	}
	
	@Override
	public int compareTo(Polynomial o) {
		return this.exponent - o.exponent;
	}
	
	@Override
	public boolean equals(Object o) {
		return this.equals((Polynomial)o);
	}
	
	public boolean equals(Polynomial o) {
		return this.exponent == ((Polynomial)o).exponent && this.unknown == ((Polynomial)o).unknown;
	}
	
	@Override
	public String toString() {
		StringBuilder res = new StringBuilder();
		if(Math.abs(this.coefficient) != 1) {
			res.append(Math.abs(this.coefficient));
		}
		switch(this.exponent) {
			case 0:
				break;
			case 1:
				res.append(this.unknown);
				break;
			default:
				String temp = String.format("%s^", this.unknown);
				if(this.getExponent() < 0) {
					res.append(temp).append("(").append(this.exponent).append(")");
				}else {
					res.append(temp).append(this.exponent);
				}
				break;
		}
		return res.toString();
	}
	
	public int getCoefficient() {
		return coefficient;
	}

	public void setCoefficient(int coefficient) {
		this.coefficient = coefficient;
	}
	

	public int getExponent() {
		return exponent;
	}
	
	@Override
	public Polynomial clone() {
		return new Polynomial(this.coefficient,this.exponent);
	}

	public Polynomial plus(Polynomial data) {
		return new Polynomial(this.coefficient + data.coefficient, this.exponent);
	}
	
	public Polynomial mutiply(Polynomial data) {
		Polynomial res = null;
		if(this.unknown == data.unknown) {
			res = new Polynomial(this.coefficient * data.getCoefficient(), this.exponent + data.getExponent());
		}
		return res;
	}
}
