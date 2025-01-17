#include "libft.h"
#include "token.h"
#include "env_manager.h"

char	*jump_quotes(char *cur, int c)
{
	if (c != '\'' && c != '\"')
		return (cur);
	while (*cur)
	{
		cur = ft_strchr(cur + 1, c);
		if (cur == NULL || *(cur - 1) != '\\')
			break ;
		//++cur;
	}
	return (cur);
}

/*
	조건
	1. 기본적으로 공백을 기준으로 토큰을 쪼갠다.
	2. 따옴표안의 공백은 문자열로 판단한다.
*/
t_tok_list	*tokenizer(char *input)
{
	t_tok_list	*ret;
	char		*begin;
	char		*end;

	ret = new_tok_list();
	begin = input;
	while (*begin)
	{
		while (ft_isspace(*begin))
			++begin;
		end = begin;
		while (*end && ft_strchr("<>|", *begin) == NULL \
					&& ft_strchr("<>| ", *end) == NULL)
			end = jump_quotes(end, *end) + 1;
		if (ft_strchr("<>|", *begin) || (end - begin == 1 && *begin == '\\'))
			++end;
		if (*begin && *begin == *(begin + 1) && ft_strchr("<>", *begin))
			++end;
		if (*begin)
		{
			insert_tok_end(ret, new_token(ft_substr(begin, 0, end - begin)));
			begin = end;
		}
	}
	return (ret);
}


