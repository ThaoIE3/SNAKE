#ifndef STRUCT_H_INCLUDED
#define STRUCT_H_INCLUDED
enum TrangThai { UP,DOWN,LEFT,RIGHT };

struct moto
{
    int mau;
    char kitu;
};

struct ToaDo
{
    int x,y;
};

struct Snake
{
    ToaDo dot[31];
    int n;
    TrangThai tt;
    int diem;
};

struct HoaQua
{
    ToaDo td;
};

#endif // STRUCT_H_INCLUDED
