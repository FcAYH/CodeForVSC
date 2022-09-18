print("Let's practice everything")
print('You\'d need to know \'bout escapes with \\ that do:')
print('\n newlines and \t tabs.')

poem = """
\tThe lovely world
with logic so firmly planted
cannot discern \n the needs of love
nor comprehend passion from intuition
and requires an explantaion
\n\twhere there is none.
"""

print("---------------------------")
print(poem)
print("---------------------------")

five = 10 - 2 + 3 - 6
print(f"This should be five: {five}")


def secret_formula(started):
    jelly_beans = started * 500
    jars = jelly_beans / 100
    crates = jars / 100
    return jelly_beans, jars, crates


start_point = 1000
beans, jars, crates = secret_formula(start_point)

# remreber that this is another way to format a string
print("With a strating point of: {}".format(start_point))
# it's just like with an f"" string
print(f"We'd have {beans} beans, {jars} jars, {crates} crates.")

start_point /= 10

print("We can also do that this way:")
formula = secret_formula(start_point)
# this is an easy way to apply a list to a format string
print("We'd have {} beans, {} jars, {} crates.".format(*formula))
