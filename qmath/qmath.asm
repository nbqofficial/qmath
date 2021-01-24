; QMATH by nbq

.code

	_abs proc
		mulss xmm0, xmm0
		sqrtss xmm0, xmm0
		ret
	_abs endp

	_min proc
		minss xmm0, xmm1
		ret
	_min endp

	_max proc
		maxss xmm0, xmm1
		ret
	_max endp

	_floor proc
		roundps xmm0, xmm0, 9
		ret
	_floor endp

	_pow proc
		movss xmm1, xmm0
		__loop:
			mulss xmm0, xmm1
			dec rdx
			cmp rdx, 1
			jne __loop
		ret
	_pow endp

	_sqrt proc
		sqrtss xmm0, xmm0
		ret
	_sqrt endp

end