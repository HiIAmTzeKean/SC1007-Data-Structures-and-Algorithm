Following is the psudocode

```
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