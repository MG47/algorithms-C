/*
* Program to study container_of macro usage
*/

#include <stdio.h>
#include <stdlib.h>

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)

#define container_of(ptr, type, member) ({		\
const typeof( ((type *)0)->member ) *__mptr = (ptr);	\
(type *)( (char *)__mptr - offsetof(type,member) );})


struct header
{
	unsigned int version;
	unsigned int data_len;
};

struct buffer {
	struct header hdr;
	void *data;
};

void test_container_of(struct header *cur_hdr)
{
	struct buffer *new_buf = NULL;

	/* 'new_buf' should now point to 'buf' in main() */
	new_buf = container_of(cur_hdr, struct buffer, hdr);
	new_buf->hdr.version = 0x11111111;
	new_buf->hdr.data_len = 0x400;
}

int main()
{
	struct buffer *buf;
	struct header *cur_hdr;

	buf = malloc(sizeof(struct buffer));
	if (!buf) {
		exit(EXIT_FAILURE);
	}

	cur_hdr = &buf->hdr;
	cur_hdr->version = 0xFFFFFFFF;
	cur_hdr->data_len = 0x100;

	printf("buf : hdr version 0x%x\n", buf->hdr.version);
	printf("buf : hdr data_len %u\n", buf->hdr.data_len);

	test_container_of(cur_hdr);

	printf("buf : hdr version 0x%x\n", buf->hdr.version);
	printf("buf : hdr data_len %u\n", buf->hdr.data_len);

        return 0;
}

