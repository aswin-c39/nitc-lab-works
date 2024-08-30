module b230213cs_aswin_2_tb();
  reg [7:0] A;
  reg [7:0] B;
  reg Cin;
  wire [7:0] S;
  wire Cout;
  b230213cs_aswin_2 subtractor(A,B,S,cout,cin);
   initial begin
    
    $monitor("A = %b, B = %b, Cin = %b : S = %b, Cout = %b", A, B, Cin, S, Cout);
	 A = 8'b00000000;
    B = 8'b00000000;
    Cin = 1'b0;
	 #10;

    // Test case 1
    A = 8'b00001111; B = 8'b00000001; 
    #10; 
	 
	 // Test case 2
    A = 8'b00001111; B = 8'b00000111;
    #10;
	 
	 // Test case 4
    A = 8'b11111111; B = 8'b00000001; 
    #10;
	 // Test case 5
    A = 8'b10101010; B = 8'b01010101; 
    #10; 

 
    $finish;
  end

endmodule