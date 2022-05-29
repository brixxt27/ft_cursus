#include "get_next_line.h"

if (node->index != -1)
{
	if (copy_static_to_string(node, &string) == EXIST) //copy_buffer_to_string 이름 변경 고려
		return (copy_string_to_ret_and_add_nul(&string, ret));
}

t_stat	copy_static_to_string(t_util *curr, t_string *ps)
{
	// 기존에 있는 개행 뒤의 문자열 curr->buf 을 ps->str 에 담음
	// if curr->buf 에서 1 byte 씩 담다가 개행이 있다면
	// 	개행까지 string 에 담고 EXIST 반환
	// 담으면서 curr->index++, ps->len++
	size_t	copy_len;

	copy_len = BUFFER_SIZE - curr->index;
	while (copy_len--)
	{
		ps->*str++ = curr->buf[(curr->index)++];
	}
}