import numpy as np


list = [ [0.00,	-0.0764, 0], [0.05,	-0.0874, 0], [0.10,	-0.0874, 0], [0.15,	-0.0774, 0], [0.20,	-0.0584, 0], [0.25,	-0.0324, 0], [0.30,	-0.0034, 0], [0.35,	0.0266 , 0], [0.40,	0.0526 , 0], [0.45,	0.0736 , 0], [0.50,	0.0856 , 0], [0.55,	0.0876 , 0], [0.60,	0.0796 , 0], [0.65,	0.0626 , 0], [0.70,	0.0386 , 0], [0.75,	0.0096 , 0], [0.80,	-0.0204, 0], [0.85,	-0.0474, 0], [0.90,	-0.0694, 0], [0.95,	-0.0834, 0], [1.00,	-0.0884, 0], [1.05,	-0.0824, 0], [1.10,	-0.0664, 0], [1.15,	-0.0434, 0], [1.20,	-0.0154, 0], [1.25,	0.0146 , 0], [1.30,	0.0426 , 0], [1.35,	0.0656 , 0], [1.40,	0.0816 , 0], [1.45,	0.0876 , 0], [1.50,	0.0836 , 0], [1.55,	0.0706 , 0], [1.60,	0.0486 , 0], [1.65,	0.0216 , 0], [1.70,	-0.0084, 0], [1.75,	-0.0374, 0], [1.80,	-0.0614, 0], [1.85,	-0.0794, 0], [1.90,	-0.0874, 0], [1.95,	-0.0854, 0], [2.00,	-0.0734, 0], [2.05,	-0.0534, 0], [2.10,	-0.0274, 0], [2.15,	0.0026 , 0], [2.20,	0.0316 , 0], [2.25,	0.0566 , 0], [2.30,	0.0756 , 0], [2.35,	0.0866 , 0], [2.40,	0.0866 , 0], [2.45,	0.0766 , 0], [2.50,	0.0576 , 0], [2.55,	0.0326 , 0], [2.60,	0.0036 , 0], [2.65,	-0.0264, 0], [2.70,	-0.0524, 0], [2.75,	-0.0724, 0], [2.80,	-0.0854, 0], [2.85,	-0.0874, 0], [2.90,	-0.0794, 0], [2.95,	-0.0624, 0], [3.00,	-0.0384, 0], [3.05,	-0.0094, 0], [3.10,	0.0206 , 0], [3.15,	0.0476 , 0], [3.20,	0.0696 , 0], [3.25,	0.0836 , 0], [3.30,	0.0876 , 0], [3.35,	0.0816 , 0], [3.40,	0.0666 , 0], [3.45,	0.0436 , 0], [3.50,	0.0156 , 0], [3.55,	-0.0144, 0], [3.60,	-0.0424, 0], [3.65,	-0.0654, 0], [3.70,	-0.0814, 0], [3.75,	-0.0874, 0], [3.80,	-0.0834, 0], [3.85,	-0.0694, 0], [3.90,	-0.0484, 0], [3.95,	-0.0214, 0], [4.00,	0.0086 , 0], [4.05,	0.0366 , 0], [4.10,	0.0616 , 0], [4.15,	0.0786 , 0], [4.20,	0.0866 , 0], [4.25,	0.0846 , 0], [4.30,	0.0736 , 0], [4.35,	0.0526 , 0], [4.40,	0.0266 , 0], [4.45,	-0.0024, 0], [4.50,	-0.0314, 0], [4.55,	-0.0564, 0], [4.60,	-0.0754, 0], [4.65,	-0.0854, 0], [4.70,	-0.0854, 0], [4.75,	-0.0764, 0], [4.80,	-0.0574, 0], [4.85,	-0.0324, 0], [4.90,	-0.0034, 0], [4.95,	0.0256 , 0], [5.00,	0.0526 , 0], [5.05,	0.0726 , 0], [5.10,	0.0846 , 0], [5.15,	0.0866 , 0], [5.20,	0.0786 , 0], [5.25,	0.0626 , 0], [5.30,	0.0386 , 0], [5.35,	0.0096 , 0], [5.40,	-0.0194, 0], [5.45,	-0.0464, 0], [5.50,	-0.0684, 0], [5.55,	-0.0824, 0], [5.60,	-0.0864, 0], [5.65,	-0.0814, 0], [5.70,	-0.0654, 0], [5.75,	-0.0434, 0], [5.80,	-0.0154, 0], [5.85,	0.0146 , 0], [5.90,	0.0426 , 0], [5.95,	0.0656 , 0], [6.00,	0.0806 , 0], [6.05,	0.0866 , 0], [6.10,	0.0836 , 0], [6.15,	0.0696 , 0], [6.20,	0.0486 , 0], [6.25,	0.0216 , 0], [6.30,	-0.0084, 0], [6.35,	-0.0364, 0], [6.40,	-0.0604, 0], [6.45,	-0.0774, 0], [6.50,	-0.0854, 0], [6.55,	-0.0844, 0], [6.60,	-0.0724, 0], [6.65,	-0.0524, 0], [6.70,	-0.0264, 0], [6.75,	0.0026 , 0], [6.80,	0.0316 , 0], [6.85,	0.0566 , 0], [6.90,	0.0756 , 0], [6.95,	0.0856 , 0], [7.00,	0.0856 , 0], [7.05,	0.0756 , 0], [7.10,	0.0576 , 0], [7.15,	0.0326 , 0], [7.20,	0.0036 , 0], [7.25,	-0.0254, 0], [7.30,	-0.0514, 0], [7.35,	-0.0714, 0], [7.40,	-0.0834, 0], [7.45,	-0.0854, 0], [7.50,	-0.0784, 0], [7.55,	-0.0614, 0], [7.60,	-0.0374, 0], [7.65,	-0.0094, 0], [7.70,	0.0196 , 0], [7.75,	0.0466 , 0], [7.80,	0.0686 , 0], [7.85,	0.0826 , 0], [7.90,	0.0866 , 0], [7.95,	0.0806 , 0], [8.00,	0.0656 , 0], [8.05,	0.0436 , 0], [8.10,	0.0156 , 0], [8.15,	-0.0134, 0], [8.20,	-0.0414, 0], [8.25,	-0.0644, 0], [8.30,	-0.0794, 0], [8.35,	-0.0864, 0], [8.40,	-0.0824, 0], [8.45,	-0.0694, 0], [8.50,	-0.0474, 0], [8.55,	-0.0214, 0], [8.60,	0.0076 , 0], [8.65,	0.0366 , 0], [8.70,	0.0606 , 0], [8.75,	0.0776 , 0], [8.80,	0.0856 , 0], [8.85,	0.0836 , 0], [8.90,	0.0726 , 0], [8.95,	0.0526 , 0], [9.00,	0.0276 , 0], [9.05,	-0.0014, 0], [9.10,	-0.0304, 0], [9.15,	-0.0554, 0], [9.20,	-0.0744, 0], [9.25,	-0.0844, 0], [9.30,	-0.0844, 0], [9.35,	-0.0754, 0], [9.40,	-0.0574, 0], [9.45,	-0.0324, 0], [9.50,	-0.0034, 0], [9.55,	0.0256 , 0], [9.60,	0.0516 , 0], [9.65,	0.0716 , 0], [9.70,	0.0836 , 0], [9.75,	0.0856 , 0], [9.80,	0.0776 , 0], [9.85,	0.0616 , 0], [9.90,	0.0376 , 0], [9.95,	0.0096 , 0], [10.00,	-0.0194, 0], [10.05,	-0.0464, 0], [10.10,	-0.0674, 0], [10.15,	-0.0814, 0], [10.20,	-0.0854, 0], [10.25,	-0.0794, 0], [10.30,	-0.0654, 0], [10.35,	-0.0424, 0], [10.40,	-0.0154, 0], [10.45,	0.0136 , 0] ]

posi = [-0.0764 ,-0.0874 ,-0.0874 ,-0.0774 ,-0.0584 ,-0.0324 ,-0.0034 ,0.0266 ,0.0526 ,0.0736 ,0.0856 ,0.0876 ,0.0796 ,0.0626 ,0.0386 ,0.0096 ,-0.0204 ,-0.0474 ,-0.0694 ,-0.0834 ,-0.0884 ,-0.0824 ,-0.0664 ,-0.0434 ,-0.0154 ,0.0146 ,0.0426 ,0.0656 ,0.0816 ,0.0876 ,0.0836 ,0.0706 ,0.0486 ,0.0216 ,-0.0084 ,-0.0374 ,-0.0614 ,-0.0794 ,-0.0874 ,-0.0854 ,-0.0734 ,-0.0534 ,-0.0274 ,0.0026 ,0.0316 ,0.0566 ,0.0756 ,0.0866 ,0.0866 ,0.0766 ,0.0576 ,0.0326 ,0.0036 ,-0.0264 ,-0.0524 ,-0.0724 ,-0.0854 ,-0.0874 ,-0.0794 ,-0.0624 ,-0.0384 ,-0.0094 ,0.0206 ,0.0476 ,0.0696 ,0.0836 ,0.0876 ,0.0816 ,0.0666 ,0.0436 ,0.0156 ,-0.0144 ,-0.0424 ,-0.0654 ,-0.0814 ,-0.0874 ,-0.0834 ,-0.0694 ,-0.0484 ,-0.0214 ,0.0086 ,0.0366 ,0.0616 ,0.0786 ,0.0866 ,0.0846 ,0.0736 ,0.0526 ,0.0266 ,-0.0024 ,-0.0314 ,-0.0564 ,-0.0754 ,-0.0854 ,-0.0854 ,-0.0764 ,-0.0574 ,-0.0324 ,-0.0034 ,0.0256 ,0.0526 ,0.0726 ,0.0846 ,0.0866 ,0.0786 ,0.0626 ,0.0386 ,0.0096 ,-0.0194 ,-0.0464 ,-0.0684 ,-0.0824 ,-0.0864 ,-0.0814 ,-0.0654 ,-0.0434 ,-0.0154 ,0.0146 ,0.0426 ,0.0656 ,0.0806 ,0.0866 ,0.0836 ,0.0696 ,0.0486 ,0.0216 ,-0.0084 ,-0.0364 ,-0.0604 ,-0.0774 ,-0.0854 ,-0.0844 ,-0.0724 ,-0.0524 ,-0.0264 ,0.0026 ,0.0316 ,0.0566 ,0.0756 ,0.0856 ,0.0856 ,0.0756 ,0.0576 ,0.0326 ,0.0036 ,-0.0254 ,-0.0514 ,-0.0714 ,-0.0834 ,-0.0854 ,-0.0784 ,-0.0614 ,-0.0374 ,-0.0094 ,0.0196 ,0.0466 ,0.0686 ,0.0826 ,0.0866 ,0.0806 ,0.0656 ,0.0436 ,0.0156 ,-0.0134 ,-0.0414 ,-0.0644 ,-0.0794 ,-0.0864 ,-0.0824 ,-0.0694 ,-0.0474 ,-0.0214 ,0.0076 ,0.0366 ,0.0606 ,0.0776 ,0.0856 ,0.0836 ,0.0726 ,0.0526 ,0.0276 ,-0.0014 ,-0.0304 ,-0.0554 ,-0.0744 ,-0.0844 ,-0.0844 ,-0.0754 ,-0.0574 ,-0.0324 ,-0.0034 ,0.0256 ,0.0516 ,0.0716 ,0.0836 ,0.0856 ,0.0776 ,0.0616 ,0.0376 ,0.0096 ,-0.0194 ,-0.0464 ,-0.0674 ,-0.0814 ,-0.0854 ,-0.0794 ,-0.0654 ,-0.0424 ,-0.0154 ,0.0136 ]
 


for i in range( len( posi ) ):
    if (i + 1) < len(posi):
        if posi[i] > posi[i-1] and posi[i] > posi[i+1]:
            print(posi[i])

for i in list:
    print(i[1])






















































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































