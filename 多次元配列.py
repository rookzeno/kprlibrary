def make_array(n,init_elem=0,td=1):
       dimension=len(n)
       if td>=dimension:
           return [init_elem for i in range(n[td-1])]
       else:
           return [make_array(n,init_elem,td+1) for i in range(n[td-1])]
