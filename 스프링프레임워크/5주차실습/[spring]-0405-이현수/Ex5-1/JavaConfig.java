package Ex4_2;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class JavaConfig {
	@Bean
	public OperatorBean operatorBean() {
		return new PlusOp(operand(), operand());
	}
	
	@Bean
	public Operand operand() {
		return new Operand(30);
	}
}
