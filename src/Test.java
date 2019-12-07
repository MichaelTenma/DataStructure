/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


//import com.ltiex.LinkedList.LinkedList;
import com.ltiex.PolynomialList.Polynomial;
import com.ltiex.PolynomialList.PolynomialList;

public class Test {

    public static void main(String[] args) {
//    	String str1[] = {"a","b","c","f","h","z"};
//    	String str2[] = {"c","d","i","j","k"};
//        LinkedList<String> list = new LinkedList<String>(str1);
//        LinkedList<String> bList = new LinkedList<String>(str2);
//        for(int i = 0;i < 10;i++){
//            list.addFromTail(i);
//        }
//        
//        for(int i = 5;i < 20;i++){
//            bList.addFromTail(i);
//        }
//        list = bList.mergeList(list);

//        boolean res = list.insertAfter(0,10);
//        System.out.println("res:" + res);
//        System.out.println(list);
        
        
    	Polynomial aPoly[] = new Polynomial[2];
    	for(int i = 0;i < 2;i++) {
    		aPoly[i] = new Polynomial(i+1,aPoly.length-i);
    	}
    	
    	Polynomial bPoly[] = new Polynomial[3];
    	bPoly[0] = new Polynomial(-1, 2);
    	bPoly[1] = new Polynomial(2, 4);
    	bPoly[2] = new Polynomial(-3, -4);
    	
        PolynomialList aList = new PolynomialList(aPoly);
        PolynomialList bList = new PolynomialList(bPoly);
        System.out.printf("  [( %s ) + ( %s )]\n* ( %s )",aList,bList,bList);
        System.out.printf("\n= %s\n",(aList.plus(bList).mutiply(bList)));

    }
    
}
