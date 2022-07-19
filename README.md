# 17.-C-MODULE-06

# Casts
### 1. 5 Conversion types
* [Conversion types](#Conversion)  
* [Reinterpretation types ](#Reinterpretation-types)  
* [Qualifier reinterpretation types ](#Reinterpretation-types)  
* [Downcast / Upcast](#Downcast-/-Upcast)
### 2. Cast C++
* [Static cast](#Static-cast)
* [Dynamic cast](#Dynamic_cast)  
* [Reinterpret cast](#Reinterpret-cast)  
* [Const cast ](#Const-cast)
### 3. Operators types & Explicit
* [Type cast operator](#Type-cast-operator)  
* [Explicit](#Explicit)

## 1. 5 Conversion types
>  Conversion = Changement de type = Reorganisation des bits pour garder la même valeur. Ch
```C
int    a;
double b = a;                 // Implicit conversion cast  + implicit promotion
double c = (double) a;        // Explicit conversion cast
int    d = (int) n;           // Implicit demotion
```

### Reinterpretation types
> Reinterpretation = conversion identitaire = Changement de type d'adresse
> void * est le type le plus générale, moins précis 
```
float a;
void   b  = &a;               // Implicit reinterpretation cast
void * b  = (void *) a;       // Implicit reinterpretation cast

void * d  = &a;               // Implicit promotion 
int  * e  = d;                // Implicit demotion    -> Bad ! 
int  * f   = (int *) d;       // Explicit demotion
```

### Type qualifier reinterpretation (example = const)
>  The reinterpretation needs to be explicit otherwise does not compile.
```C

int const * d = 1;
int       * e = d;            // Implicit demotion -> WARNING, doesn't compile
int       * e = (int *)d;     // Explicit demotion 
```
### Downcast / Upcast
>  The reinterpretation needs to be explicit otherwise does not compile.
>  Une classe parent est plus générale que la classe enfant.

## 2. C++ casts

### Static cast
>  En C++, on utilise static_cast<type> pour downcast, upcast and conversion dans la même hierarchie de classes.
```C
int         a = 42;
double      b = a;                       // Implicit promotion 
int       * e = static_cast<int>(b);     // Explicit demotion 
```

### Dynamic cast
>  Le cast se fait à l'execution. De plus il faut qu'il y ait une méthode dans la classe. (Polymorphisme par sous-typage)
```C++
class Parent {public : virtual ~Parent(void) {}};
class Child1 : public Parent {};
class Child2 : public Parent {};

Child1       a;
Parent      *b = &a;                       // Implicit upcast
try
{
  Child1      *c = dynamic_cast<Child1 *>(b);
  Child2     & d = dynamic_cast<Child2 &>(*b);    -> error
}
catch (std::bad_cast &bc)
{
  cout << "Cast error" << endl;
}
```
### Reinterpret cast
>  Le cast le plus permissif. Il convertit anyway.
```C++
float     a = 420.042f;

void    * b = & a;
int     * c = reinterpret_cast<int *> (b);  -> ok
int     & d = reinterpret_cast<int &> (b);  -> ok
```
### Const cast  (should not be used)
>  Le cast entre type constant et type mutable. = cast de qualifieur de type
```C++
float     a = 420.042f;

void    * b = & a;
int     * c = reinterpret_cast<int *> (b);  -> ok
int     & d = const_cast<int &> (b);  -> ok
```
## 3. Operators & Explicit

### Type cast operator 
>  Allow to implicit cast thanks to the class.
```C++
class foo {
  public :
      operator float() {return _value ;}
      operator int()   {return static_cast<int>(_value) ;}
  private :
      float _value;}
     
    foo   a(420.024f);
    float b = a;
    int   c = a;     
```

### Explicit
>  No conversion is allowed in the constructor.


