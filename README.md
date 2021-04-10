## So I had to recode ft_printf... 👨‍💻

...and this is my very naive attempt at it.

### Why? 

42 Cursus assignment (check [the subject](https://github.com/protsaq/ft_printf/blob/master/rsch/en.subject.pdf) for more details). 

### What with?

Standard C functions that were previously recoded (the ``libft`` directory), variadic functions and not much more. If you clone this repo, *these won't be accessible straight away*. Follow the very easy [Git documentation on submodules](https://git-scm.com/book/en/v2/Git-Tools-Submodules) to be able to import the library. ¹

### Oh, nice! Tell us more!

A friend relayed a web comment on how ``print_f`` was really not that hard - all it took was a little planning and organisation. I'm terrible at both. 

Thus I spent the first three or four days endlessly reading the ``man`` page and the *great* resource at the [die.net directory of web pages](https://linux.die.net/man/3/printf) (which definitely doesn't provide medical information about assisted life termination ⚰️ or any other medical practice I might not be aware of, just in case the website domain had you wondering). 

At some point, I got the impression the code could actually be very concise and clean, and set to do the assignment with the goal of having - and now please bear with me, while we necessarily delve in on some very technical programming jargon I'm about to throw at you - and so I set to do it, as I was saying, with 👄 *very sexy code* ✨.

The project is done and the code is good - in fact, I haven't yet seen anyone tackle the mandatory part with such code economy. As for efficiency, if the fed source string proposes *n* conversions, then the code makes *n* mallocs and *2n + 1* writes. There are still areas that could be slightly optimised - but, alas, not even with a ten foot pole I would be touching this project again (but I did enjoy it very much, and am indeed very proud of what was accomplished). 

### That was unexpected! So where would you find information on legal medical practices, and, while we're at it, some other websites whose domain is a verb in the infinitive?

That is not really the question I was looking for, and so I present my definition of very sexy code: 

- **it should be concise, and avoid redundancies.** If possible, do not have seven functions that to pretty much the same thing (there are still a couple of perpetrators in my code, though) 🧩
- **it should be linear and not hard to follow.** Let it be closer to a single thread, instead of having weird branching outs and unnecessary/unelegant auxiliary functions 🧵
- **it should be easily [extensible](https://english.stackexchange.com/questions/90426/extensible-vs-extendible#90444) .** If I ever were to tackle the bonus conversions, little to no adjustments should be necessary to the main code 🧱
- **it can have *some* obtuse code**, as long as the idea is worth it and the implementation is not too insufferable - people are not stupid, and, this being a practice assignment, it's nice to see some new tricks every now and then. Luckily, I don't think the code is too hard to understand 🧞‍♂️

### So is your code sexy, then?

~~As much as non-working, 6/694 [test passing](https://github.com/gavinfielder/pft) code can be, yes, definitely yes.~~ 

~~At the time of writing, it seems like the code handles conversions somewhat well, but there is no actual printing done. So there's that to work on ASAP. 🕰~~

It is, yes - it follows what I initially proposed as *the right approach* and does it well. It's sad to think I just peaked my whole 42 career.

### Why would an obsessively edited README, littered with plenty of unnecessary references and bad taste in jokes, be a better use of a waking hour over having the code work better  and, you know, actually making some progress in your life?

Ok so first, let's be a little more careful with what you call a bad taste in jokes alright because there's like a whole spectrum of things people can find funny, or have you ever not seen really cute cats doing silly things, and this was me just trying to make a couple people laugh at their computers by the way everyone should really try and stretch regularly that would do wonders for the posture and so back at you if you ever do any of those snide remarks about the way I take my living I might just 

### Oh, man -- sorry for triggering that out of you. But you really should let your emotions run wild. Do you need someone to talk to?

Not really - and thanks for asking - but I have to thank a great many colleagues for both the emotional support and patience of saints, as I am well aware of having drilled them daily about my approach and progress. Special mentions to **msessa** for the guidance and very honest feedback; **ncameir** for being very enthusiastic about the whole idea; **rramos** for constantly grounding my feet everytime I got too enthusiastic about the end product, and the most precious **mvaldeta** who never lets anyone feel alone in any coding endeavour. The others shall remain unnamed and we'll very soon meet for some phisically demanding activity! 🏓

¹ run `git submodule init`, and then `git submodule update`. It's that easy. 
