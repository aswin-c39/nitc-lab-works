module B230213CS_ASWIN_2_tb;

  reg clk;
  reg rst;
  reg coin5;
  reg coin10;
  
  wire dispense;
  wire return_change;
  
  B230213CS_ASWIN_2 uut(
	.clk(clk),
	.rst(rst),
	.coin5(coin5),
	.coin10(coin10),
	.dispense(dispense),
	.return_change(return_change)
  );
  
  always #5 clk = ~clk;
  
  initial begin
		clk = 0;
		rst = 0;
		coin5 = 0;
		coin10 = 0;
		
		#10 rst = 1;
		$display("reset");
			// Test case 1: Insert a 5 coin
		 #10;
        coin5 = 1'b1; 
        #10;
        coin5 = 1'b0; 

        // Test Case 2: Insert another 5 coin
        #20;
        coin5 = 1'b1; 
        #10;
        coin5 = 1'b0; 

        // Test Case 3: Insert a 10 coin to reach 15
        #20;
        coin10 = 1'b1; 
        #10;
        coin10 = 1'b0; 

        // Test Case 4: Insert a 10 coin (should dispense and return change)
        #20;
        coin10 = 1'b1; 
        #10;
        coin10 = 1'b0; 
		  
		  #20;
		  coin10 = 1'b1;
		  #10;
		  coin10 = 1'b0;
		  
		  #20;
		  coin5 = 1'b1;
		  #30;
		  coin5 = 1'b0;
			
			
        // Wait for a few clock cycles
        #50;
        $finish;
    end

    initial begin
        $monitor("Time: %d, cur_state: %b, coin5: %b, coin10: %b, dispense: %b, return_change: %b", 
                 $time, uut.cur_state, coin5, coin10, dispense, return_change);
    end
endmodule

