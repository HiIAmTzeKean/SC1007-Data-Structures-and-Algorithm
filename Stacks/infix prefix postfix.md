# infix prefix postfix

## Post to pre

```
// Read from front of string to back
While not end of string
    if (isOperand)
        push(item)
    if (isOpt)
    {
        // Pop 2 operands
        R=pop()
        L=pop()
        push(opt + L + R)
    }
```

## Pre to post

Following is the pseudocode

```
// Read from back of string to front
while not exceed start of string
    if (isOperand)
        push(item) to stack
    if (isOpt)
    {
        // Proceed to pop 2 out of the stack
        L=pop(item)
        R=pop(item)
        push(L + R + Opt)
    }
```
