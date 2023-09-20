```python
# As a language, Python does not have versions with incompatible syntax.
# However, here's your script updated to Python 3. If there's a specific
# feature or syntax you want to use from a specific version, please specify:

# gaussian_elimination.py

def gaussian_elimination(a):
    n = len(a)
    
    for i in range(n):
        max_el = abs(a[i][i])
        max_row = i
        for k in range(i+1, n):
            if abs(a[k][i]) > max_el:
                max_el = abs(a[k][i])
                max_row = k
        
        a[i], a[max_row] = a[max_row], a[i]
        
        for k in range(i+1, n):
            c = -a[k][i]/a[i][i]
            for j in range(i, n+1):
                if i == j:
                    a[k][j] = 0
                else:
                    a[k][j] += c * a[i][j]
    
    x = [0 for _ in range(n)]
    for i in range(n-1, -1, -1):
        x[i] = a[i][n]/a[i][i]
        for k in range(i-1, -1, -1):
            a[k][n] -= a[k][i] * x[i]
    return x
```