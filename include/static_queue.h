#ifndef __STATIC_QUEUE_H__
#define __STATIC_QUEUE_H__

//#include <linux/ktime.h>
//#include <linux/types.h>
#include <linux/slab.h>
#include <linux/kthread.h> // for kthread
#include <linux/sched.h>   // for task_struct
#include <linux/delay.h>   // for sleep, delay API

#include "pktinfo.h"

struct s_queue_data {
    struct sk_buff skb;
    struct gtp5g_pktinfo pktinfo;
};

struct static_queue {
    struct s_queue_data *data;
    int s_queue_id;
    int front;
    int rear;
    int size;
    int capacity;
    struct task_struct *queue_kthread;
};

extern void create_s_queue(struct static_queue *, int, int);
extern void s_queue_push(struct static_queue *, struct sk_buff *, struct gtp5g_pktinfo *);
extern void s_queue_pop(struct static_queue *);
extern struct s_queue_data s_queue_get_front(struct static_queue *);
extern struct s_queue_data s_queue_get_rear(struct static_queue *);
extern void s_queue_display(struct static_queue *);

#endif // __STATIC_QUEUE_H__