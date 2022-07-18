# 17.-C-MODULE-06

# Casts
* [Conversion types](#Conversion)  
* [Reinterpretation types ](#Reinterpretation-types)  
* [Qualifier reinterpretation types ](#Reinterpretation-types)  
* [Downcast / Upcast](#Downcast-/-Upcast)  
* [Static cast](#Static-cast)  
* [Reinterpretation types ](#Reinterpretation-types)  
* [Qualifier reinterpretation types ](#Reinterpretation-types)  

### Conversion types
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

### Static cast
>  The reinterpretation needs to be explicit otherwise does not compile.
```C
int const * d = 1;
int       * e = d;            // Implicit demotion -> WARNING, doesn't compile
int       * e = (int *)d;     // Explicit demotion 
```
