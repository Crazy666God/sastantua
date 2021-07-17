#include <stdio.h>

void ft_putchar(char c)
{
  fwrite(&c, sizeof(c), 1, stdout);
}

int calc_base(int size)
{
  int level = 1;
  int width = 1;
  int level_step = 4;
  while(level <= size)
  {
    width += 2 * (2 + level);
    ++level;
    width += level_step;
    if(level % 2 && level < size)
      level_step += 2;
  }
  width -= level_step;
  return width;
}

void put_blocks(int base, int width, int level, int size, int step)
{
  int spase = base - width;
  for(int i = 0; i < spase / 2; ++i)
      ft_putchar(' ');
  ft_putchar('/');
  int door = 1 + 2 * ((level - 1) / 2);
  for(int i = 1; i < width - 1; ++i)
  {
    if(level == size && i >= (width - door) / 2 && i < (width + door) / 2 && 2 + level - step <= door)
      if(door >= 3 && step == (2 + level - door / 2 - 1) && i == ((width + door) / 2 - 2))
        ft_putchar('$');
      else
        ft_putchar('|');
    else
      ft_putchar('*');
  }
  ft_putchar('\\'); 
  for(int i = 0; i < spase / 2; ++i)
      ft_putchar(' '); 
  ft_putchar('\n');
}

void santantua(int size)
{
  if(size < 1)
    return;
  int height = 3;
  int level = 1; 
  int width = 1;
  int level_step = 4;
  int step = 0;
  int base = calc_base(size);
  while(level <= size)
  {
    while(step < height)
    {
      width += 2;
      put_blocks(base, width, level, size, step);
      ++step;
    }
    ++level;
    if(level % 2 && level < size)
      { 
        width += level_step;
        level_step += 2;
      }
    else
        width += level_step;
    step = 0;
    ++height;
  }
}

int main(void)
{
  int size;
  printf("Введите размер пирамиды = ");
  scanf("%d", &size);
  santantua(size);
  return 0;
}

