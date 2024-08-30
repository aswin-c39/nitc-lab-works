module b230213cs_aswin_2(A,B,S,Cout,Cin);

	input [7:0]A;
	input [7:0]B;
	input Cin;

	output [7:0]S;
	output Cout;
	
	wire c1,c2,c3,c4,c5,c6,c7;

	wire w1, w2, w3, w4, w5, w6, w7, w8, w9;

	xor(w1, B[0], 1);
	xor(w2, B[1], 1);
	xor(w3, B[2], 1);
	xor(w4, B[3], 1);
	xor(w5, B[4], 1);
	xor(w6, B[5], 1);
	xor(w7, B[6], 1);
	xor(w8, B[7], 1);
   or (w9, 1'b0, Cin);
	
	full_adder add1(A[0],w1,w9,S[0],c1), add2(A[1],w2,c1,S[1],c2), add3(A[2],w3,c2,S[2],c3), add4(A[3],w4,c3,S[3],c4);
   full_adder add5(A[4],w5,c4,S[4],c5), add6(A[5],w6,c5,S[5],c6), add7(A[6],w7,c6,S[6],c7), add8(A[7],w8,c7,S[7],cout);

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