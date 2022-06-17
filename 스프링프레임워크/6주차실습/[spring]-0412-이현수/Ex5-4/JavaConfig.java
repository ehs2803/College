package Ex4_2;

import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.ImportResource;
import org.springframework.context.annotation.Scope;

@Configuration
@ImportResource("classpath:appCtxEx6_4.xml")
public class JavaConfig {
	@Bean
	public OperatorBean operatorBean() {
		OperatorBean plusop = new PlusOp();
		//plusop.setOperand1(operand());  autowired
		//plusop.setOperand2(operand());
		return plusop;
	}
	
}
