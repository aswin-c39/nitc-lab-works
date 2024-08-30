module b230213cs_aswin_3(A,B,sel,R);

input [7:0]A,B;
input [1:0]sel;

output [7:0]R;

wire [7:0]d0,d1,d2,d3;
wire cout;

adder_subtractor_7 add(A,B,1'b0,d0,cout),sub(A,B,1'b1,d1,cout);
eight_bit_xor xor1(A,B,d2);
left_shift shifter1(A,d3);

mux_4x1 mux1(d0,d1,d2,d3,sel,R);

endmodule

//half adder
module half_adder(a, b, sum, carry);

input a, b;
output sum, carry;

xor(sum, a, b);
and(carry, a, b);

endmodule

//full adder
module full_adder(a, b, cin, sum, cout);

input a, b, cin;
output sum, cout;

wire w1, w2, w3, w4;

half_adder half1(a, b, w1, w2), half2(cin, w1, sum, w3);
or(cout, w2, w3);

endmodule

//4bit add or sub
module four_bit_add_sub(A,B,K,S,Cout,Cin);

input [3:0]A;
input [3:0]B;
input K, Cin;

output [3:0]S;
output Cout;

wire w1, w2, w3, w4, w5, w6, w7, w8;

xor(w1, B[0], K);
xor(w2, B[1], K);
xor(w3, B[2], K);
xor(w4, B[3], K);
   or (w8, 1'b0, Cin);
   full_adder full1(A[0], w1, w8, S[0], w5), full2(A[1], w2, w5, S[1], w6), full3(A[2], w3, w6, S[2], w7), full4(A[3], w4, w7, S[3], Cout);

endmodule


//8bit add or sub
module adder_subtractor_7(A, B, k, S, Cout);

input [7:0]A;
input [7:0]B;
input k;

output [7:0]S;
output Cout;

wire w1;

  four_bit_add_sub four1(A[3:0], B[3:0], k, S[3:0], w1, k), four2(A[7:4], B[7:4], k, S[7:4], cout, w1);

endmodule


module eight_bit_xor(A,B,Y);

input [7:0]A,B;
output [7:0]Y;

xor(Y[0],A[0],B[0]); xor(Y[1],A[1],B[1]); xor(Y[2],A[2],B[2]); xor(Y[3],A[3],B[3]);
xor(Y[4],A[4],B[4]); xor(Y[5],A[5],B[5]); xor(Y[6],A[6],B[6]); xor(Y[7],A[7],B[7]);

endmodule

module left_shift(A, R);

input [31:0]A;
output [31:0]R;

and(R[0], 1'b0, 1'b1); and(R[1], A[0], 1'b1); and(R[2], A[1], 1'b1); and(R[3], A[2], 1'b1);
and(R[4], A[3], 1'b1); and(R[5], A[4], 1'b1); and(R[6], A[5], 1'b1); and(R[7], A[6], 1'b1);

endmodule

module AND8(A, B, R);

input [7:0]A,B;
output [7:0]R;

and(R[0], A[0], B[0]); and(R[1], A[1], B[1]); and(R[2], A[2], B[2]); and(R[3], A[3], B[3]);
and(R[4], A[4], B[4]); and(R[5], A[5], B[5]); and(R[6], A[6], B[6]); and(R[7], A[7], B[7]);

endmodule

module NOT8(A, R);

input [7:0]A;
output [7:0]R;

not(R[0], A[0]); not(R[1], A[1]); not(R[2], A[2]); not(R[3], A[3]);
not(R[4], A[4]); not(R[5], A[5]); not(R[6], A[6]); not(R[7], A[7]);

endmodule

module OR32(A, B, R);

input [7:0]A,B;
output [7:0]R;

or(R[0], A[0], B[0]); or(R[1], A[1], B[1]); or(R[2], A[2], B[2]); or(R[3], A[3], B[3]);
or(R[4], A[4], B[4]); or(R[5], A[5], B[5]); or(R[6], A[6], B[6]); or(R[7], A[7], B[7]);

endmodule

module duplicate(R, S);
input S;
output [31:0]R;

and(R[0], S, 1'b1);and(R[1], S, 1'b1);and(R[2], S, 1'b1);and(R[3], S, 1'b1);
and(R[4], S, 1'b1);and(R[5], S, 1'b1);and(R[6], S, 1'b1);and(R[7], S, 1'b1);

endmodule

//4x1 mux with 8 bit inputs
module mux_4x1( d0,  d1,  d2,  d3, sel, data_out);
    input [7:0] d0,  d1,  d2,  d3;
  input [1:0]sel;
    output [7:0] data_out;
    wire [7:0] w0, w1, w2, w3,s0,s1,nots0,nots1,a1,a2,a3;
 

duplicate dup1(s0, sel[0]),dup2(s1,sel[1]);

NOT7 not1(s0,nots0),not2(s1,nots1);

AND7 and1(nots0,nots1,a1), and2(a1,d0,w0);
AND7 and3(s0,nots1,a2), and4(a2,d1,w1);
AND7 and5(nots0,s1,a3), and6(a3,d2,w2);
AND7 and7(s0,s1,a4), and8(a4,d3,w3);

OR7 or1(w0,w1,o1),or2(o1,w2,o2),or3(o2,w3,data_out);

endmodule
