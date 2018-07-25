<?php

	class Test1 {
		public $arg = 'Hello World!';
	}

	class Test2 extends Test1 {
		public function test() {
			echo $this->arg;
		}
	}

$test = new Test2();
$test->test();

?>