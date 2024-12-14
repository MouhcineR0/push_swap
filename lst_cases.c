/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_cases.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmouhcin <rmouhcin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:56:18 by rmouhcin          #+#    #+#             */
/*   Updated: 2024/12/14 23:50:51 by rmouhcin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// sa swap first 2 elements in stack a
// sb swap first 2 elements in stack b
// ss sa + sb
// pa push first elements of stack bi and put it in top of stack a
// pb push first elements of stack a and put it in top of stack b
// ra Shift up all elements of stack a by 1 The first element becomes the last one.
// rb  Shift up all elements of stack b by 1 The first element becomes the last one
// rr ra + rb
// rra Shift down all elements of stack a by 1 The last element becomes the first one.
// rrb Shift down all elements of stack b by 1 The last element becomes the first one.
// rrr rra + rrb

#include "push_swap.h"

void	lst_case_2(t_stack *stack)
{
	if (stack->arr[0] > stack->arr[1])
		sa(stack,1);
}
void	lst_case_3(t_stack *stack)
{
	if (stack->arr[0] > stack->arr[1] && stack->arr[1] > stack->arr[2]) // 3 2 1
		sa(stack,1),rra(stack,1);
	else if (stack->arr[0] < stack->arr[1] && stack->arr[1] > stack->arr[2] && stack->arr[0] > stack->arr[2]) // 2 3 1
		rra(stack,1);
	else if (stack->arr[0] > stack->arr[1] && stack->arr[1] < stack->arr[2] && stack->arr[0] > stack->arr[2]) // 3 1 2
		rra(stack,1),rra(stack,1);
	else if (stack->arr[0] < stack->arr[1] && stack->arr[1] > stack->arr[2] && stack->arr[0] < stack->arr[2]) // 1 3 2
		rra(stack,1),sa(stack,1);
	else if (stack->arr[0] > stack->arr[1] && stack->arr[1] < stack->arr[2] && stack->arr[0] < stack->arr[2]) // 2 1 3
		sa(stack,1);
}

void	lst_case_4_5(t_stack *a,t_stack *b)
{
	int min_index;

	if (a->length == 3)
		lst_case_3(a);
	else if (a->length == 2)
		lst_case_2(a);
	else if (a->length == 4)
	{
		min_index = lst_min(a->arr,a->length) + 1;
		if (min_index > a->length / 2 )
		{
			while (min_index != a->length + 1 && min_index++)
				rra(a,1);
		}
		else if (min_index <= a->length / 2 )
		{
			while (--min_index)
				ra(a,1);
		}
		pb(a,b);
		lst_case_3(a);
		pa(a,b);
	}
	else
		lst_case_5(a,b);
}
void	lst_case_5(t_stack *a,t_stack *b)
{
	int min_index;

	min_index = lst_min(a->arr,a->length) + 1;
	if (min_index > a->length / 2 )
	{
		while (min_index != a->length + 1 && min_index++)
			rra(a,1);
	}
	else if (min_index <= a->length / 2 )
	{
		while (--min_index)
			ra(a,1);
	}
	pb(a,b);
	lst_case_4_5(a,b);
	pa(a,b);
}
// hadi khatta2
void	sort_shunk(t_stack *a,t_stack *b)
{
	int sum;

	sum = b->length;
	while (sum >= 5)
		sum -= 5;
	// while (b->length)
	// {
	// 	// if (b->length >= 5 && (!sum || sum == -1) && (sum = -1))
	// 	// {
			
	// 	// }
	// 	else if (b->length >= 3 && (sum == 3 || sum == -1) && (sum = -1))
	// 	{
	// 		if (b->arr[0] > b->arr[1] && b->arr[1] > b->arr[2]) // 3 2 1
	// 			pa(a,b),pa(a,b),pa(a,b);
	// 		else if (b->arr[0] < b->arr[1] && b->arr[1] > b->arr[2] && b->arr[0] > b->arr[2]) // 2 3 1
	// 			rb(b,1),pa(a,b),rrb(b,1),pa(a,b),pa(a,b);
	// 		else if (b->arr[0] > b->arr[1] && b->arr[1] < b->arr[2] && b->arr[0] > b->arr[2]) // 3 1 2
	// 			pa(a,b),rb(b,1),pa(a,b),rrb(b,1),pa(a,b);
	// 		else if (b->arr[0] < b->arr[1] && b->arr[1] > b->arr[2] && b->arr[0] < b->arr[2]) // 1 3 2
	// 			rb(b,1),pa(a,b),pa(a,b),rrb(b,1),pa(a,b);
	// 		else if (b->arr[0] > b->arr[1] && b->arr[1] < b->arr[2] && b->arr[0] < b->arr[2]) // 2 1 3
	// 			rb(b,1),rb(b,1),pa(a,b),rrb(b,1),rrb(b,1),pa(a,b),pa(a,b);
	// 		else
	// 			rb(b,1),rb(b,1),pa(a,b),rrb(b,1),pa(a,b),rrb(b,1),pa(a,b);
	// 	}
	// 	else if (sum == 2 && (sum = -1))
	// 	{
	// 		if (b->arr[0] > b->arr[1])
	// 			pa(a,b),pa(a,b);
	// 		else
	// 			rb(b,1),pa(a,b),rrb(b,1),pa(a,b);
	// 	}
	// 	else if (sum == 1 && (sum = -1))
	// 		pa(a,b);
	// }
	while (b->length)
	{
		int index_max;
		int return_rotate;

		index_max = lst_max(b->arr,b->length);
		// ft_printf("((%d))",index_max);
		return_rotate = index_max;
		while (index_max--)
			rb(b,1);
		pa(a,b);
		while (return_rotate--)
			rrb(b,1);
	}
}
// i will do chunks method with 10 elements
// search for elements of the first shank lte7t w lfog w nchuf l9riba w nrotati 3la wdha w npushiha
// wla ndir be3da ghir chanks b 5 elements w nchuf wach 9lal les instructions

int	shank_element(t_stack *shank,t_stack *a,int shank_length)
{
	int left;
	int right;
	int i;

	left = 0;
	right = a->length - 1;
	// i = 0;
	// while (i < shank_length)
	// {
	// 	if (shank->arr[i] == a->arr[0])
	// 		return (0);
	// 	i++;
	// }
	while (left <= right)
	{
		i = 0;
		while (i < shank_length) // this should change depend on chank size
		{
			if (shank->arr[i] == a->arr[left])
			{
				// ft_printf("[[[%d %d]]] -> ",left,a->arr[left]);
				// ft_printf("[[[%d %d]]]",i,shank->arr[i]);
				return (left);
			}
			else if (shank->arr[i] == a->arr[right])
			{
				// ft_printf("[[[%d %d]]] -> ",left,a->arr[left]);
				// ft_printf("[[[%d %d]]]",i,shank->arr[i]);
				return (right);
			}
			i++;
		}
		left++;
		right--;
	}
	return (-1);
}

void push_a(t_stack *a,t_stack *b,int index)
{
	if (index < b->length / 2)
	{
		while (index > 0 && index--)
		{
			rb(b,1);
		}
		pa(a,b);
	}
	else if (b->length / 2 <= index)
	{
		while (b->length != index++)
		{
			rrb(b,1);
		}
		pa(a,b);
	}
}

// fach kansiftu l index lwl itpusha kaytbdel lina les index dyal table cuz kaytrotata
// probleme kan f b->length bach kan endixiw array sorted.arr
// error indexing just test and t3jeb mzyan 
// [][ 860647 , 460979 , 524945 , 917686 , 801533 , 952914 , 794332 , 888235 , 677616 , 885849 , 724838 , 935738 , 588446 , 585324 , 501095 , 638345 , 618712 , 471559 , 652660 , 545956 , 435766 , 119317 , 417006 , 165764 , 428897 , 123483 , 123364 , 352647 , 187484 , 329416 , 327618 , 222406 , 108615 , 375930 , 185662 , 306892 , 422896 , 136026 , 335596 , 307182 , -121722 , -154891 , 69307 , -233627 , 64656 , -225463 , -321450 , -242751 , -53924 , 41643 , -199215 , -70263 , 97921 , -74985 , -37324 , -362522 , -124828 , -3485 , -332423 , -72543 , -548166 , -396556 , -497873 , -638407 , -371382 , -413491 , -685611 , -429490 , -627928 , -583519 , -574015 , -365563 , -632623 , -368198 , -459277 , -551933 , -690168 , -453473 , -647226 , -678353 , -772152 , -915536 , -834427 , -955697 , -967281 , -949764 , -901060 , -699705 , -732410 , -697151 , -748085 , -765779 , -724651 , -691147 , -882041 , -855159 , -914728 , -990270 , -851913 , -701627 ]
// [[[[5]]]]
// [[[[11]]]]
// rb
// rb
// rb
// rb
// rb
// pa
// pa
// sa
// [ 952914 , 794332 ][ 888235 , 677616 , 885849 , 724838 , 935738 , 588446 , 585324 , 501095 , 638345 , 618712 , 471559 , 652660 , 545956 , 435766 , 119317 , 417006 , 165764 , 428897 , 123483 , 123364 , 352647 , 187484 , 329416 , 327618 , 222406 , 108615 , 375930 , 185662 , 306892 , 422896 , 136026 , 335596 , 307182 , -121722 , -154891 , 69307 , -233627 , 64656 , -225463 , -321450 , -242751 , -53924 , 41643 , -199215 , -70263 , 97921 , -74985 , -37324 , -362522 , -124828 , -3485 , -332423 , -72543 , -548166 , -396556 , -497873 , -638407 , -371382 , -413491 , -685611 , -429490 , -627928 , -583519 , -574015 , -365563 , -632623 , -368198 , -459277 , -551933 , -690168 , -453473 , -647226 , -678353 , -772152 , -915536 , -834427 , -955697 , -967281 , -949764 , -901060 , -699705 , -732410 , -697151 , -748085 , -765779 , -724651 , -691147 , -882041 , -855159 , -914728 , -990270 , -851913 , -701627 , 860647 , 460979 , 524945 , 917686 , 801533 ]
// [[[[96]]]]
// [[[[0]]]]
void push_swap(t_stack *a,t_stack *b)
{
	int max_index;
	int max_minus_index;
	int should_swap;

	should_swap = 0;
	// sorted array stack :
	t_stack sorted_arr;
	sorted_arr.arr = (int *) malloc(b->length * sizeof(int));
	lst_cpy(b->arr,sorted_arr.arr,b->length);
	sorted_arr.length = b->length;
	lst_sort(sorted_arr.arr,sorted_arr.length);
	// int i = b->length -;
	
	while (b->length)
	{
		if (b->length >= 2)
		{
			max_minus_index = lst_index_of(b->arr,sorted_arr.length,sorted_arr.arr[sorted_arr.length - 1]);
			// max_minus_index = -1;
			max_index = lst_index_of(b->arr,sorted_arr.length,sorted_arr.arr[sorted_arr.length - 2]);
			lst_print(a->arr,a->length);
			lst_print(b->arr,b->length);
			ft_printf("\n[[[[%d]]]]\n",max_minus_index);
			ft_printf("[[[[%d]]]]\n",max_index);
			// lst_print(b->arr,b->length);
			// return ;
		}
		else if (b->length == 1)
		{
			// max_index = lst_index_of(b->arr,sorted_arr.length,sorted_arr.arr[sorted_arr.length - 1]);
			// max_minus_index = -1;
			return ;
		}
		if (max_index >= b->length / 2 && max_minus_index >= b->length / 2 && max_minus_index != -1)
		{
			if (max_index > max_minus_index)
			{
				push_a(a,b,max_index);
				push_a(a,b,lst_index_of(b->arr,sorted_arr.length,sorted_arr.arr[sorted_arr.length - 2]) + 1);
			}
			else if (max_index <= max_minus_index)
			{
				push_a(a,b,max_minus_index);	
				push_a(a,b,lst_index_of(b->arr,sorted_arr.length,sorted_arr.arr[sorted_arr.length - 1]) + 1);
				sa(a,1);
			}
		}
		else if (max_index <= b->length / 2 && max_minus_index <= b->length / 2 && max_minus_index != -1)
		{
			if (max_index < max_minus_index)
			{
				push_a(a,b,max_index);
				push_a(a,b,lst_index_of(b->arr,sorted_arr.length,sorted_arr.arr[sorted_arr.length - 2]) + 1);
			}
			else if (max_index >= max_minus_index)
			{
				push_a(a,b,max_minus_index);	
				push_a(a,b,lst_index_of(b->arr,sorted_arr.length,sorted_arr.arr[sorted_arr.length - 1]) + 1);
				sa(a,1);
			}
		}
		else if (max_index <= b->length / 2 && max_minus_index >= b->length / 2 && max_minus_index != -1)
		{
			if (max_index < b->length - max_minus_index)
			{
				push_a(a,b,max_index);
				push_a(a,b,lst_index_of(b->arr,sorted_arr.length,sorted_arr.arr[sorted_arr.length - 2]) + 1);
			}
			else {
				push_a(a,b,max_minus_index);
				push_a(a,b,lst_index_of(b->arr,sorted_arr.length,sorted_arr.arr[sorted_arr.length - 1]) + 1);
				sa(a,1);
			}
		}
		else if (max_index >= b->length / 2 && max_minus_index <= b->length / 2 && max_minus_index != -1) // warning
		{
			if (max_index < b->length - max_minus_index)
			{
				push_a(a,b,max_index);
				push_a(a,b,lst_index_of(b->arr,sorted_arr.length,sorted_arr.arr[sorted_arr.length - 2]) + 1);
			}
			else {
				push_a(a,b,max_minus_index);
				push_a(a,b,lst_index_of(b->arr,sorted_arr.length,sorted_arr.arr[sorted_arr.length - 1]) + 1);
				sa(a,1);
			}
		}
		else
			push_a(a,b,max_index);
		if (max_minus_index != -1)
			sorted_arr.length -= 2;
		else
			sorted_arr.length--;
	}
	// ft_printf("[[[[%d]]]]",i);
}
// void push_swap(t_stack *a,t_stack *b)
// {
// 	int max_index;
// 	int i = 0;
// 	while (b->length)
// 	{
// 		max_index = lst_max(b->arr,b->length);
// 		if (max_index < b->length / 2)
// 		{
// 			while (max_index--)
// 			{
// 				rb(b,1);i++;
// 			}
// 			pa(a,b);i++;
// 		}
// 		else if (b->length / 2 <= max_index)
// 		{
// 			while (b->length != max_index++)
// 			{
// 				rrb(b,1);i++;
// 			}
// 			pa(a,b);i++;
// 		}
// 	}
// 	ft_printf("((((%d))))",i);
// }


// nbdaw n9su 5 b 5 ila b9at lina chi 7aja 9el mn 5 npushiwha kamla
void lst_large_case(t_stack *a,t_stack *b, int shank_length)
{
	t_stack sorted_arr;
	int tmp;

	tmp = -1;
	int i = 0;
	sorted_arr.arr = (int *) malloc(a->length * sizeof(int));
	lst_cpy(a->arr,sorted_arr.arr,a->length);
	sorted_arr.length = a->length;
	lst_sort(sorted_arr.arr,sorted_arr.length);

	while (a->length >= shank_length) // this should change depend on chank size
	{
		// ft_printf("h");
		tmp = shank_element(&sorted_arr,a,shank_length);
		if (tmp != -1)
		{
			if (tmp < a->length / 2)
			{
				while (tmp--)
					ra(a,1);i++;
				pb(a,b);i++;
			}
			else if (a->length / 2 <= tmp)
			{
				while (a->length != tmp++)
					rra(a,1);i++;
				pb(a,b);i++;
			}
			tmp = -1;
		}
		else
		{
			int k = shank_length; // this should change depend on chank size
			while (k--)
				rb(&sorted_arr,0);
			sorted_arr.length -= shank_length; // this should change depend on chank size
		}
	}
	// if (a->length <= 5) // sort remaining in stack a
	// 	lst_case_4_5(a,b);
	// else
	while (a->length)
		pb(a,b);
	// ft_printf("[[[%d]]]",i);
	push_swap(a,b);
}