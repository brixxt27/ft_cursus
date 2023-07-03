### 이슈 관리: [전체 이슈 list](https://github.com/brixxt27/ft_cursus/issues/2)

---

Assignment name:	microshell

Expected file:		*.c *.h

Allowed function:	malloc, free, write, close, fork, waitpid, signal, kill, chdir, execve, dup, dup2, pipe, strcmp, strncmp

---

아래와 같은 프로그램을 작성하시오.
1. 실행하기 위한 command line 은 프로그램의 인자가 될 것이다.
- The command line to execute will be the arguments of this program

2. 명령어 path 는 절대 경로  또는 상대 경로여야 하지만, 프로그램이 path 를 만들지 않는다.(예를 들어 PATH 변수)
- Executable's path will be absolute or relative but your program must not build a path (from the PATH variable for example)

3. | 과 ; 를 bash와 같이 구현해야 한다
	- 우리는 아무 것도 오지 않았거나 '|' 나 ';' 이 있을 때, 즉시 '|' 가 따라오거나 선행되는 시도를 하지 않을 것이다.
- You must implement "|" and ";" like in bash
	- we will never try a "|" immediately followed or preceded by nothing or "|" or ";"

4. 이 프로그램은 인자로 하나의 경로를 받는 built-in command cd 를 구현할 것이다.(- 과 인자가 없는 경우는 없다)
	- 만약 cd 가 프로그램 인자 수를 잘못 받았다면, stderr 로 "error: cd: bad arguments\n" 출력해야 한다.
	- 만약 프로그램이 실패한다면 stderr 로 "error: cd: cannot change directory to {path_to_change}\n" 을 출력해야 하는데 {path_to_change} 에는 cd의 인자를 넣어야 한다.
	- cd 는 | 의 뒤나 앞에 붙지 오지 않는다.
- Your program must implement the built-in command cd only with a path as argument (no '-' or without parameters)
	- if cd has the wrong number of argument your program should print in STDERR "error: cd: bad arguments" followed by a '\n'
	- if cd failed your program should print in STDERR "error: cd: cannot change directory to path_to_change" followed by a '\n' with path_to_change replaced by the argument to cd
	- a cd command will never be immediately followed or preceded by a "|"

5. wildcards 에 대한 처리를 하지 않아도 된다.
- You don't need to manage any type of wildcards (*, ~ etc...)

6. 환경 변수에 대한 처리를 하지 않아도 된다.
- You don't need to manage environment variables ($BLA ...)

7. execve 와 chdir 를 제외한 시스템 콜이 에러를 반환한다면, 프로그램은 즉시 "error: fatal\n" 를 stderr 로 출력하고, 프로그램은 종료해야 한다.
- If a system call, except execve and chdir, returns an error your program should immediatly print "error: fatal" in STDERR followed by a '\n' and the program should exit

8. 만약 execve 가 실패한다면, 프로그램은 stderr 로 "error: cannot execute {executable_that_failed}\n" 출력해야 한다. {executable_that_failed} 는 실패한 프로그램의 경로로 대체되어야 한다. (execve의 첫 인자가 될 것이다)
- If execve failed you should print "error: cannot execute executable_that_failed" in STDERR followed by a '\n' with executable_that_failed replaced with the path of the failed executable (It should be the first argument of execve)

9. 프로그램은 천 개 보다 많은 | 를 처리할 수 있어야 한다. 심지어 열린 파일의 수를 30개 이하로 제한하더라도!
- Your program should be able to manage more than hundreds of "|" even if we limit the number of "open files" to less than 30.


for example this should work:
```
$>./microshell /bin/ls "|" /usr/bin/grep microshell ";" /bin/echo i love my microshell
microshell
i love my microshell
$>

./microshell /bin/echo WOOT "; /bin/echo NOPE;" "; ;" ";" /bin/echo YEAH
WOOT ; /bin/echo NOPE; ; ;
YEAH
$>

./microshell "ls" "|" /usr/bin/grep _____ ";" /bin/cp /usr/bin/grep ./ ";" /bin/ls "|" ./grep grep 2> error.log; cat error.log
grep
error: cannot execute ls
$>
```
Hint:
	1) execve 에 환경변수를 넣는 것을 잊지 마세요!
	2) file descriptors 의 close 를 잊지 마세요!
