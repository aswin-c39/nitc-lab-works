module b230213cs_aswin_1(A,B,S,Cout,Cin);

	input [7:0]A;
	input [7:0]B;
	input Cin;

	output [7:0]S;
	output Cout;
	wire c1,c2,c3,c4,c5,c6,c7;
	
  full_adder add1(A[0],B[0],cin,S[0],c1), add2(A[1],B[1],c1,S[1],c2), add3(A[2],B[2],c2,S[2],c3), add4(A[3],B[3],c3,S[3],c4);
  full_adder add5(A[4],B[4],c4,S[4],c5), add6(A[5],B[5],c5,S[5],c6), add7(A[6],B[6],c6,S[6],c7), add8(A[7],B[7],c7,S[7],cout);

endmodule

module half_adder(a, b, sum, carry);
	
	input a, b;
	output sum, carry;
	
	xor(sum, a, b);
	and(carry, a, b);

endmodule


module full_adder(a, b, cin, sum, cout);

	input a, b, cin;
	output sum, cout;
	
	wire w1, w2, w3, w4;	
	
	half_adder half1(a, b, w1, w2), half2(cin, w1, sum, w3);
	or(cout, w2, w3);
	
endmodule
