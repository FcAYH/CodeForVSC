module gal_3035_4(clk,c0,Q,en,x);     

    input clk,en,x;
    output c0,Q;
    reg[13:0] Q;
    reg c0 ;   //可为寄存器输出型

    always@(posedge clk or negedge en)
    begin
        if(!en)     
        begin      
            Q <= 0;
            c0 <= 0;
        end
        else if(!x)
                begin
                    if(Q == 8237)      
                    begin
                        c0 <= ~c0; //时钟翻转
                        Q<= 0;     //计数清零
                    end
                    else Q <= Q + 1;
                end
                else
                begin
                    if(Q >= 1918)    //这里要用>=，因为当x变成1时，可能Q是1918到8237之间的数
                    begin
                        c0 <= ~c0; //时钟翻转
                        Q<= 0;     //计数清零
                    end
                    else Q <= Q + 1;
                end
            
    end
    
endmodule
