Week 4
======

Binary Search Tree
----------------------

**Property**
> X's key is larger than the key of any descendent of its left child, and smaller than the key of any descendent of its right child
> 
> <img src="pics/QQ20161009-4@2x.png" alt="Drawing" style="width: 400px;"/>
> 


**Balance**
> Want left and right subtrees to have approximately the same size


**Desirable Properties**

> - **h** should be fast to compute
> - Different values for different objects
> - Direct addressing with O(m) memory
> - Want small cardinalty **m**
> - Impssible to have all different values if number of objects |**S**| is more than m


**Definition**: Collisions
> when h(o<sub>1</sub>)=h(o<sub>1</sub>) and o<sub>1</sub> != o<sub>2</sub>, this is a collision.


**Definition**: Map
> Map from S to V is a data structure with methods HasKey(O), Get(O), Set(O, v), where O ∈ S, v ∈ V.

**Hash Functions**

 <img src="pics/QQ20161009-1@2x.png" alt="Drawing" style="width: 400px;"/> <img src="pics/QQ20161009-2@2x.png" alt="Drawing" style="width: 400px;"/> <img src="pics/QQ20161009-3@2x.png" alt="Drawing" style="width: 400px;"/>
