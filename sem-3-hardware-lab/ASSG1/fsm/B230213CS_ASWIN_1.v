module B230213CS_ASWIN_1(
	input wire clk,
	input wire rst_n,
	input wire data,
	output reg seq_detected
	
);

parameter s0 = 3'b000,
			 s1 = 3'b001,
			 s2 = 3'b010,
			 s3 = 3'b011,
			 s4 = 3'b100;

reg [2:0] cur_state, next_state;

always @(posedge clk or negedge rst_n) begin
	if(!rst_n)
		cur_state <= s0;
	else
		cur_state <= next_state;
end
	
always @(cur_state,data) begin
	case (cur_state)
		s0: begin
			if(data == 1'b1)
				next_state = s1;
			else
				next_state = s0;
		end
		
		s1: begin
			if(data == 1'b1)
				next_state = s2;
			else
				next_state = s0;
		end
		
		s2: begin
			if(data == 1'b0)
				next_state = s3;
			else 
				next_state = s0;
		end
		
		s3: begin
			if(data == 1'b1)
				next_state = s4;
			else
				next_state = s0;
		end
		
		s4: begin
			next_state = s0;
		end
		
		default: begin
			next_state = s0;
		end
	endcase
end 

always @(cur_state) begin
	case(cur_state)
		s4:begin 
			seq_detected = 1'b1;
		end
		
		default: begin
			seq_detected = 1'b0;
		end
	endcase
	
end

endmodule
		